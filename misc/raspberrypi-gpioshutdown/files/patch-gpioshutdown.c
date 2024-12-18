--- gpioshutdown.c.orig	2024-12-18 02:17:41 UTC
+++ gpioshutdown.c
@@ -199,7 +199,7 @@ static int internal_shutdown_pre_sync(void *arg1 __unu
 
 static int internal_shutdown_pre_sync(void *arg1 __unused)
 {
-int nMaxUnit, nUnit, nPinBase, max_pin, res;
+int nMaxUnit, nUnit, nPinBase, max_pin;
 devclass_t dc;
 device_t dev;
 
@@ -234,7 +234,7 @@ device_t dev;
       {
         max_pin = 0;
 
-        res = GPIO_PIN_MAX(dev, &max_pin);
+        GPIO_PIN_MAX(dev, &max_pin);
 
         if(led_gpio >= nPinBase && led_gpio <= max_pin + nPinBase)
         {
@@ -242,11 +242,11 @@ device_t dev;
 
           pin = led_gpio - nPinBase;
 
-          res = GPIO_PIN_GETFLAGS(dev, pin, &val);
+          GPIO_PIN_GETFLAGS(dev, pin, &val);
           if(!(val & GPIO_PIN_OUTPUT))
           {
             int caps;
-            res = GPIO_PIN_GETCAPS(dev, pin, &caps);
+            GPIO_PIN_GETCAPS(dev, pin, &caps);
 
             if(caps & GPIO_PIN_OUTPUT) // it CAN be an input - see gpio_check_flags() in gpiobus.c
             {
