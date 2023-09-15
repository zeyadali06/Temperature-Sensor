#include <DHT.h>
#include <LiquidCrystal.h>

#define mot1 3
#define mot2 4

LiquidCrystal lcd(10, 12, 8, 7, 6, 5);

int hum, temp ;

const byte DHT_PIN = 13;
const byte DHT_TYPE = 11;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16,2);
    pinMode(mot1, OUTPUT);
    pinMode(mot2, OUTPUT);
}

void loop() {
    // Wait a few seconds between measurements.
   
    delay(2000);
    lcd.clear();

       // Read humidity
        hum = dht.readHumidity();

       // Read temperature as Celsius (the default)
       temp = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(hum) || isnan(temp)) {
        Serial.println("Failed to read from DHT sensor!");
        return;}

        if(temp >= 20 )
        {

         digitalWrite(mot1, LOW);
         digitalWrite(mot2, HIGH);

        } 
        else {
         digitalWrite(mot1, LOW);
         digitalWrite(mot2, LOW);
        }
        
        lcd.print("T:"); 
        lcd.print(temp);
        lcd.print("c");
        
        lcd.print("      H:");
        lcd.print(hum);
        lcd.print("%");


        Serial.print("Humidity: ");
        Serial.print(hum);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.print(" Â°C\t ");
        Serial.println();
    }