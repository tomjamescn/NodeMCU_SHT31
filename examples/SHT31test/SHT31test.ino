#include <NodeMCU_SHT31.h>

#define PIN_SCL 14        // I2C Bus SCL (clock), this is ok for any kit based on esp8266
#define PIN_SDA 2         // I2C Bus SDA (data), this is ok for any kit based on esp8266
#define ADDR_SHT31 0x44   // default sht31 address, set to 0x45 for alternate i2c addr

NodeMCU_SHT31 sht31 = NodeMCU_SHT31();

void setup() {
  Serial.begin(9600);
  Serial.println("NodeMCU SHT31 setup");
  while (!Serial);

  if (! sht31.begin(PIN_SDA, PIN_SCL, ADDR_SHT31)) {
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }

  Serial.println("setp NodeMCU SHT31 is OK!");
}

void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) {  // check if 'is not a number'
    Serial.print("Temp *C = "); Serial.println(t);
  } else { 
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) {  // check if 'is not a number'
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("Failed to read humidity");
  }
  Serial.println();
  delay(1000);
}