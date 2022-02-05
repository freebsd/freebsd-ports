--- lcdapi/sensors/LCDSensor.h.orig	2022-02-05 21:39:20 UTC
+++ lcdapi/sensors/LCDSensor.h
@@ -53,12 +53,12 @@ class LCDWidgetTimeOut {
 
  LCDWidgetTimeOut()
     : _widgetId(), _timeOut(0), _widget(NULL),
-    _thread(static_cast<pthread_t>(-1))
+    _thread(nullptr)
   {
   }
 
   bool isValid() {
-    return (_thread != static_cast<pthread_t>(-1));
+    return (_thread != nullptr);
   }
 
   const LCDWidgetTimeOut& operator=(const LCDWidgetTimeOut& rhs) {
