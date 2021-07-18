--- services/device/serial/serial_device_enumerator.cc.orig	2021-04-14 18:41:08 UTC
+++ services/device/serial/serial_device_enumerator.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "components/device_event_log/device_event_log.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "services/device/serial/serial_device_enumerator_linux.h"
 #elif defined(OS_MAC)
 #include "services/device/serial/serial_device_enumerator_mac.h"
@@ -23,7 +23,7 @@ namespace device {
 // static
 std::unique_ptr<SerialDeviceEnumerator> SerialDeviceEnumerator::Create(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return SerialDeviceEnumeratorLinux::Create();
 #elif defined(OS_MAC)
   return std::make_unique<SerialDeviceEnumeratorMac>();
