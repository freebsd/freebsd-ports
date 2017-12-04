--- device/hid/hid_service.cc.orig	2017-09-21 15:04:58.000000000 -0700
+++ device/hid/hid_service.cc	2017-12-03 15:37:32.167748000 -0800
@@ -16,6 +16,8 @@
 
 #if defined(OS_LINUX) && defined(USE_UDEV)
 #include "device/hid/hid_service_linux.h"
+#elif defined(OS_BSD)
+#include "device/hid/hid_service_freebsd.h"
 #elif defined(OS_MACOSX)
 #include "device/hid/hid_service_mac.h"
 #elif defined(OS_WIN)
@@ -42,6 +44,8 @@
 std::unique_ptr<HidService> HidService::Create() {
 #if defined(OS_LINUX) && defined(USE_UDEV)
   return base::WrapUnique(new HidServiceLinux());
+#elif defined(OS_BSD)
+  return base::WrapUnique(new HidServiceFreeBSD());
 #elif defined(OS_MACOSX)
   return base::WrapUnique(new HidServiceMac());
 #elif defined(OS_WIN)
