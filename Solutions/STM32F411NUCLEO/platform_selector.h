#ifndef _PLATFORM_STM32F411NUCLEO_SELECTOR_H_
#define _PLATFORM_STM32F411NUCLEO_SELECTOR_H_

/////////////////////////////////////////////////////////
//
// processor and features
//

#if defined(PLATFORM_ARM_STM32F411NUCLEO)

#define HAL_SYSTEM_NAME "STM32F411NUCLEO"

#define PLATFORM_ARM_STM32F4    // STM32F4XX
#define STM32F40_41xxx
#define USB_ALLOW_CONFIGURATION_OVERRIDE 1
//
// processor and features
//
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//
// constants
//

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4


#define PORT_PIN(port,pin)              (((int)port)*16 + (pin))

// System clock
#define SYSTEM_CLOCK_HZ                  96000000   //  96 MHz
#define SYSTEM_CYCLE_CLOCK_HZ            96000000   //  96 MHz
#define SYSTEM_APB1_CLOCK_HZ             48000000   //  48 MHz
#define SYSTEM_APB2_CLOCK_HZ             96000000   //  96 MHz

#define SYSTEM_CRYSTAL_CLOCK_HZ           8000000   // 8 MHz external clock that is used from STLINK Directly

#define CLOCK_COMMON_FACTOR               1000000   // GCD(SYSTEM_CLOCK_HZ, 1M)
#define SLOW_CLOCKS_PER_SECOND            1000000   // 1 MHz
#define SLOW_CLOCKS_TEN_MHZ_GCD           1000000   // GCD(SLOW_CLOCKS_PER_SECOND, 10M)
#define SLOW_CLOCKS_MILLISECOND_GCD          1000   // GCD(SLOW_CLOCKS_PER_SECOND, 1k)
#define SUPPLY_VOLTAGE_MV                    3300   // 3.3V supply

// Memory
#define FLASH_MEMORY_Base               0x08000000
#define FLASH_MEMORY_Size               0x00080000  // 512K
#define SRAM1_MEMORY_Base               0x20000000
#define SRAM1_MEMORY_Size               0x00020000  // 128K

//#define TXPROTECTRESISTOR               RESISTOR_DISABLED
//#define RXPROTECTRESISTOR               RESISTOR_DISABLED
//#define CTSPROTECTRESISTOR              RESISTOR_DISABLED
//#define RTSPROTECTRESISTOR              RESISTOR_DISABLED

//
//https://developer.mbed.org/users/mbed_official/code/mbed-dev/file/default/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F411xE/TARGET_NUCLEO_F411RE/PeripheralPins.c
//

// The remaining ports are not broken out - except PD2, PH0 and PH1, which are deliberately omitted to reduce memory consumption (PD2) and to keep the range continuous (PH0, PH1).

#define TOTAL_GPIO_PORT                 (GPIO_PORTC + 1)
#define TOTAL_GPIO_PINS                 (TOTAL_GPIO_PORT*16)

// Communication

#define TOTAL_USART_PORT                3  

#define USART_DEFAULT_PORT              COM1
#define USART_DEFAULT_BAUDRATE          115200

#define TOTAL_GENERIC_PORTS             1 // 1 generic port extensions (ITM channel 0 )
#define ITM_GENERIC_PORTNUM             0 // ITM0 is index 0 in generic port interface table

 
#define DEBUG_TEXT_PORT                 ITM0
#define STDIO                           ITM0
#define DEBUGGER_PORT                   USB1
#define MESSAGING_PORT                  USB1

#define TOTAL_USB_CONTROLLER            1
#define USB_MAX_QUEUES                  4  // 4 endpoints (EP0 + 3)

// System Timer Configuration
#define STM32F4_32B_TIMER 2
#define STM32F4_16B_TIMER 3


//ADC Channels 1 = PA0,PA1,PA4,PA5,PA6,PA7,PB0,PB1,PC0,PC1,PC2,PC3,PC4,PC5 - all possible ANALOG INPUT (need to short it just for Arduino Headers)
#define STM32F4_ADC 1
#define STM32F4_AD_CHANNELS {PORT_PIN(GPIO_PORTA,0),PORT_PIN(GPIO_PORTA,1),PORT_PIN(GPIO_PORTA,4),PORT_PIN(GPIO_PORTA,5),PORT_PIN(GPIO_PORTA,6),PORT_PIN(GPIO_PORTA,7),  PORT_PIN(GPIO_PORTB,0),PORT_PIN(GPIO_PORTB,1),PORT_PIN(GPIO_PORTC,0),PORT_PIN(GPIO_PORTC,1),PORT_PIN(GPIO_PORTC,2),PORT_PIN(GPIO_PORTC,3),PORT_PIN(GPIO_PORTC,4), PORT_PIN(GPIO_PORTA,5)}

//PWM - PA0,PA1,PA5,PA6,PA8,PA9,PA10,PA11,PA15,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PC6,PC7,PC8,PC9 - (should limit to Microsoft Limit of Provider)
#define STM32F4_PWM_TIMER {2,2,2,3,1,1,1,1,2,2,3,3,4,4,4,4,2,3,3,3,3}
#define STM32F4_PWM_CHNL  {1,2,1,1,1,2,3,4,1,2,1,2,1,2,3,4,3,1,2,3,4}
#define STM32F4_PWM_PINS  {PORT_PIN(GPIO_PORTA,0),PORT_PIN(GPIO_PORTA,1),PORT_PIN(GPIO_PORTA,5),PORT_PIN(GPIO_PORTA,6),PORT_PIN(GPIO_PORTA,8),PORT_PIN(GPIO_PORTA,9),PORT_PIN(GPIO_PORTA,10),PORT_PIN(GPIO_PORTA,11),PORT_PIN(GPIO_PORTA,15),PORT_PIN(GPIO_PORTB,3),PORT_PIN(GPIO_PORTB,4),PORT_PIN(GPIO_PORTB,5),PORT_PIN(GPIO_PORTB,6),PORT_PIN(GPIO_PORTB,7),PORT_PIN(GPIO_PORTB,8),PORT_PIN(GPIO_PORTB,9),PORT_PIN(GPIO_PORTB,10),PORT_PIN(GPIO_PORTC,6),PORT_PIN(GPIO_PORTC,7),PORT_PIN(GPIO_PORTC,8),PORT_PIN(GPIO_PORTC,9)} 

                                  // SP1                    SP2                        SP3               SP4                   //max of Microsoft.Spot,
#define STM32F4_SPI_SCLK_PINS {PORT_PIN(GPIO_PORTA,5),PORT_PIN(GPIO_PORTB,13),PORT_PIN(GPIO_PORTC,10),PORT_PIN(GPIO_PORTB,13)} // PA5, PB13, PC10 , PB13,
#define STM32F4_SPI_MISO_PINS {PORT_PIN(GPIO_PORTA,6),PORT_PIN(GPIO_PORTB,14),PORT_PIN(GPIO_PORTC,11),PORT_PIN(GPIO_PORTA,11)} // PA6, PB14, PC11 , PA11 
#define STM32F4_SPI_MOSI_PINS {PORT_PIN(GPIO_PORTA,7),PORT_PIN(GPIO_PORTB,15),PORT_PIN(GPIO_PORTC,12),PORT_PIN(GPIO_PORTA,1)}  // PA7, PB15, PC12 , PA1

#define STM32F4_I2C_PORT     1
#define STM32F4_I2C_SCL_PIN  PORT_PIN(GPIO_PORTB,8) // PB8
#define STM32F4_I2C_SDA_PIN  PORT_PIN(GPIO_PORTB,9) // PB9

//                              USART1 (APB2)              USART2 (ABP1)             USART6 (ABP2)  
#define STM32F4_UART_TXD_PINS { PORT_PIN(GPIO_PORTA,  9),  PORT_PIN(GPIO_PORTA, 2), PORT_PIN(GPIO_PORTA, 11) }
#define STM32F4_UART_RXD_PINS { PORT_PIN(GPIO_PORTA, 10),  PORT_PIN(GPIO_PORTA, 3), PORT_PIN(GPIO_PORTA, 12) }
#define STM32F4_UART_CTS_PINS { PORT_PIN(GPIO_PORTA, 11),  PORT_PIN(GPIO_PORTA, 0), (BYTE)GPIO_PIN_NONE      }  
#define STM32F4_UART_RTS_PINS { PORT_PIN(GPIO_PORTA, 12),  PORT_PIN(GPIO_PORTA, 1), (BYTE)GPIO_PIN_NONE      }  


// User LEDs
#define LED6                            PORT_PIN(GPIO_PORTA, 5) // Green
#define LED5                            PORT_PIN(GPIO_PORTA, 5) // Green
#define LED4                            PORT_PIN(GPIO_PORTA, 5) // Green
#define LED3                            PORT_PIN(GPIO_PORTA, 5) // Green
#define LED2                            PORT_PIN(GPIO_PORTA, 5) // Green
#define LED1                            PORT_PIN(GPIO_PORTA, 5) // Green

// TinyBooter entry using GPIO
#define TINYBOOTER_ENTRY_GPIO_PIN       PORT_PIN(GPIO_PORTC, 13)  // User button
#define TINYBOOTER_ENTRY_GPIO_STATE     TRUE                      // Active low
#define TINYBOOTER_ENTRY_GPIO_RESISTOR  RESISTOR_DISABLED          

//
// constants
/////////////////////////////////////////////////////////

#include <processor_selector.h>

#endif // PLATFORM_ARM_STM32F411NUCLEO

#endif // _PLATFORM_STM32F411NUCLEO_SELECTOR_H_
