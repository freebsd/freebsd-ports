--- services/device/serial/serial_device_enumerator.cc.orig	2020-05-15 15:19:57 UTC
+++ services/device/serial/serial_device_enumerator.cc
@@ -9,7 +9,7 @@
 #include "base/unguessable_token.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "services/device/serial/serial_device_enumerator_linux.h"
 #elif defined(OS_MACOSX)
 #include "services/device/serial/serial_device_enumerator_mac.h"
@@ -22,7 +22,7 @@ namespace device {
 // static
 std::unique_ptr<SerialDeviceEnumerator> SerialDeviceEnumerator::Create(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<SerialDeviceEnumeratorLinux>();
 #elif defined(OS_MACOSX)
   return std::make_unique<SerialDeviceEnumeratorMac>();
