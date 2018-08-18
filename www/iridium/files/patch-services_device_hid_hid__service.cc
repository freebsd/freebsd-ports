--- services/device/hid/hid_service.cc.orig	2018-02-24 16:25:18.000000000 +0100
+++ services/device/hid/hid_service.cc	2018-03-04 05:38:54.425730000 +0100
@@ -16,6 +16,8 @@
 
 #if defined(OS_LINUX) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif defined(OS_BSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif defined(OS_MACOSX)
 #include "services/device/hid/hid_service_mac.h"
 #elif defined(OS_WIN)
@@ -36,6 +38,8 @@
 std::unique_ptr<HidService> HidService::Create() {
 #if defined(OS_LINUX) && defined(USE_UDEV)
   return base::WrapUnique(new HidServiceLinux());
+#elif defined(OS_BSD)
+  return base::WrapUnique(new HidServiceFreeBSD());
 #elif defined(OS_MACOSX)
   return base::WrapUnique(new HidServiceMac());
 #elif defined(OS_WIN)
