#include <iostream>

// 1 << 0 = 1   (001 в двоичной) - невидимость
// 1 << 1 = 2   (010 в двоичной) - беззвучие
// 1 << 2 = 4   (100 в двоичной) - подавление волн инфракрасного спектра
// 1 << 3 = 8   (1000 в двоичной) - подавление радио
// 1 << 4 = 16 (10000 в двоичной) - энергосбережение

// Функция изменяет состояние на противоположное
void toggleState(int &suit, int stateNumber)
{
    suit = suit ^ (1 << stateNumber);
}

// Функция проверяет, активно ли состояние
bool isStateActive(int suit, int stateNumber)
{
    return suit & (1 << stateNumber);
}

// Функция считает количество активных состояний
int countActiveStates(int suit)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (suit & (1 << i))
        {
            count++;
        }
    }
    return count;
}

// Функция проверяет условия обнаружения
bool isDetected(int suit)
{
    // Пример 1: обнаружат, если невидимость (бит 0) выключена, при этом радио (бит 3) не подавлено
    if (!isStateActive(suit, 0) && !isStateActive(suit, 3))
    {
        return true;
    }
    // Пример 2: обнаружат, если невидимость включена, но подавление инфр.спектра (бит 2) выключено
    if (isStateActive(suit, 0) && !isStateActive(suit, 2))
    {
        return true;
    }
    return false;
}

int main()
{
    int suit = 0;
    // toggleState
    toggleState(suit, 0); // включаем невидимость
    toggleState(suit, 2); // включаем подавление инфракрасного спектра
    // isStateActive
    bool invisActive = isStateActive(suit, 0); // должно быть true
    bool radioActive = isStateActive(suit, 3); // должно быть false
    // countActiveStates
    int activeCount = countActiveStates(suit); // должно быть 2
    // isDetected
    bool detected = isDetected(suit); // проверяем обнаружение
    return 0;
}
