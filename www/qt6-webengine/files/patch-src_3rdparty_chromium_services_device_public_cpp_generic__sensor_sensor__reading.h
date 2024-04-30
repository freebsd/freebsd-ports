--- src/3rdparty/chromium/services/device/public/cpp/generic_sensor/sensor_reading.h.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/services/device/public/cpp/generic_sensor/sensor_reading.h
@@ -8,6 +8,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#include <cstdint>
+
 #include <type_traits>
 
 namespace device {
