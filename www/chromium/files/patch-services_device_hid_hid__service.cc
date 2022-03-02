--- services/device/hid/hid_service.cc.orig	2022-02-28 16:54:41 UTC
+++ services/device/hid/hid_service.cc
@@ -18,6 +18,10 @@
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/hid/hid_service_fido.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/hid/hid_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
@@ -61,6 +65,10 @@ constexpr base::TaskTraits HidService::kBlockingTaskTr
 std::unique_ptr<HidService> HidService::Create() {
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
   return base::WrapUnique(new HidServiceLinux());
+#elif BUILDFLAG(IS_OPENBSD)
+  return base::WrapUnique(new HidServiceFido());
+#elif BUILDFLAG(IS_FREEBSD)
+  return base::WrapUnique(new HidServiceFreeBSD());
 #elif BUILDFLAG(IS_MAC)
   return base::WrapUnique(new HidServiceMac());
 #elif BUILDFLAG(IS_WIN)
