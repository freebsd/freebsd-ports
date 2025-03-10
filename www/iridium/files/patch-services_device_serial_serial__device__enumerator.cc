--- services/device/serial/serial_device_enumerator.cc.orig	2024-08-27 06:28:16 UTC
+++ services/device/serial/serial_device_enumerator.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "components/device_event_log/device_event_log.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "services/device/serial/serial_device_enumerator_linux.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/serial/serial_device_enumerator_mac.h"
@@ -26,7 +26,7 @@ namespace device {
 // static
 std::unique_ptr<SerialDeviceEnumerator> SerialDeviceEnumerator::Create(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return SerialDeviceEnumeratorLinux::Create();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<SerialDeviceEnumeratorMac>();
