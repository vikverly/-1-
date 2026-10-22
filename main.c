/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*Студент: Черных Виктория Александровна
Группа: ПИ-1-1
Назначение: Обработка массива
*/
#include <stdio.h>

#define MAX_SIZE 100

// Прототипы функций
void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMinIndex(const int array[], int size);
int findMaxIndex(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void countPosNegZero(const int array[], int size, int *pos, int *neg, int *zero);
void countEvenOdd(const int array[], int size, int *even, int *odd);
void printElementsInRange(const int array[], int size, int a, int b);
void rotateRight(int array[], int size, int k);

int main(void) {
    int array[MAX_SIZE];
    int size;

    // 1. Запрос размера массива
    printf("Введите размер массива (от 1 до %d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    // 2. Ввод элементов
    printf("Введите %d целых чисел:\n", size);
    inputArray(array, size);

    // 3. Вывод исходного массива
    printf("\n--- Результаты обработки ---\n");
    printf("Исходный массив: ");
    printArray(array, size);

    // 4. Поиск минимума и максимума
    int minIdx = findMinIndex(array, size);
    int maxIdx = findMaxIndex(array, size);
    printf("Минимальный элемент: %d (индекс: %d)\n", array[minIdx], minIdx);
    printf("Максимальный элемент: %d (индекс: %d)\n", array[maxIdx], maxIdx);

    // 5. Сумма и среднее арифметическое
    long long sum = calculateSum(array, size);
    double avg = calculateAverage(array, size);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    // 6. Подсчет знаков
    int pos = 0, neg = 0, zero = 0;
    countPosNegZero(array, size, &pos, &neg, &zero);
    printf("Положительных: %d, Отрицательных: %d, Нулей: %d\n", pos, neg, zero);

    // 7. Подсчет четных и нечетных
    int even = 0, odd = 0;
    countEvenOdd(array, size, &even, &odd);
    printf("Чётных: %d, Нечётных: %d\n", even, odd);

    // 8. Вывод элементов в диапазоне
    int a, b;
    printf("\nВведите границы диапазона (два числа a и b): ");
    if (scanf("%d %d", &a, &b) == 2) {
        // Если пользователь перепутал границы местами, поменяем их
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printElementsInRange(array, size, a, b);
    } else {
        printf("Ошибка ввода границ.\n");
    }

    // 9. Индивидуальный вариант 7: Циклический сдвиг вправо
    int k;
    printf("\n[Вариант 7] Введите количество позиций для сдвига вправо (k): ");
    if (scanf("%d", &k) == 1) {
        rotateRight(array, size, k);
        printf("Массив после сдвига: ");
        printArray(array, size);
    } else {
        printf("Ошибка ввода k.\n");
    }

    return 0;
}

// Функция ввода массива
void inputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

// Функция вывода массива
void printArray(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Поиск индекса минимального элемента
int findMinIndex(const int array[], int size) {
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

// Поиск индекса максимального элемента
int findMaxIndex(const int array[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// Вычисление суммы
long long calculateSum(const int array[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Вычисление среднего арифметического
double calculateAverage(const int array[], int size) {
    if (size == 0) return 0.0;
    return (double)calculateSum(array, size) / size;
}

// Подсчет положительных, отрицательных и нулей
void countPosNegZero(const int array[], int size, int *pos, int *neg, int *zero) {
    *pos = 0;
    *neg = 0;
    *zero = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            (*pos)++;
        } else if (array[i] < 0) {
            (*neg)++;
        } else {
            (*zero)++;
        }
    }
}

// Подсчет чётных и нечётных
void countEvenOdd(const int array[], int size, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

// Вывод элементов в диапазоне [a, b]
void printElementsInRange(const int array[], int size, int a, int b) {
    printf("Элементы в диапазоне [%d, %d]: ", a, b);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            printf("%d ", array[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("нет таких элементов");
    }
    printf("\n"); // Здесь была ошибочная запятая, теперь всё правильно
}

// Упрощенный циклический сдвиг вправо на k позиций
void rotateRight(int array[], int size, int k) {
    if (size <= 1) return;

    // Если сдвиг больше размера массива, берем остаток от деления
    k = k % size;
    
    // Если пользователь ввел отрицательное число, переводим в эквивалентный положительный сдвиг
    if (k < 0) {
        k = k + size;
    }

    if (k == 0) return;

    // Создаем временный массив, чтобы сохранить элементы
    int temp[MAX_SIZE];

    // Шаг 1: переносим элементы на новые места во временный массив
    for (int i = 0; i < size; i++) {
        int newIndex = (i + k) % size; // куда должен встать элемент с индексом i
        temp[newIndex] = array[i];
    }

    // Шаг 2: копируем обратно из временного массива в основной
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}