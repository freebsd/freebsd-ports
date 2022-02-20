--- services/device/hid/hid_service.cc.orig	2022-02-07 13:39:41 UTC
+++ services/device/hid/hid_service.cc
@@ -18,6 +18,10 @@
 
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif defined(OS_OPENBSD)
+#include "services/device/hid/hid_service_fido.h"
+#elif defined(OS_FREEBSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif defined(OS_MAC)
 #include "services/device/hid/hid_service_mac.h"
 #elif defined(OS_WIN)
@@ -61,6 +65,10 @@ constexpr base::TaskTraits HidService::kBlockingTaskTr
 std::unique_ptr<HidService> HidService::Create() {
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_UDEV)
   return base::WrapUnique(new HidServiceLinux());
+#elif defined(OS_OPENBSD)
+  return base::WrapUnique(new HidServiceFido());
+#elif defined(OS_FREEBSD)
+  return base::WrapUnique(new HidServiceFreeBSD());
 #elif defined(OS_MAC)
   return base::WrapUnique(new HidServiceMac());
 #elif defined(OS_WIN)
