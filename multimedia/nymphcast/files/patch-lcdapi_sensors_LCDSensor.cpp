--- lcdapi/sensors/LCDSensor.cpp.orig	2022-02-05 21:52:04 UTC
+++ lcdapi/sensors/LCDSensor.cpp
@@ -36,7 +36,7 @@ const int LCDSensor::MAX_CMD_RESULT_LINE_SIZE = 255;
 LCDSensor::LCDSensor()
   : _exist(true),
     _onChangeThreadStarted(false),
-    _onChangeThread(static_cast<pthread_t>(-1)),
+    _onChangeThread(nullptr),
     _onChangeList(),
     _onTimeOutList()
 {
