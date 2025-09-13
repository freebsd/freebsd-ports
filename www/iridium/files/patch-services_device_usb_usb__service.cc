--- services/device/usb/usb_service.cc.orig	2025-09-11 13:19:19 UTC
+++ services/device/usb/usb_service.cc
@@ -20,12 +20,16 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include "services/device/usb/usb_service_android.h"
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
 #include "services/device/usb/usb_service_linux.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/usb/usb_service_impl.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/usb/usb_service_win.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/usb/usb_service_impl.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/usb/usb_service_fake.h"
 #endif
 
 namespace device {
@@ -48,11 +52,13 @@ constexpr base::TaskTraits UsbService::kBlockingTaskTr
 std::unique_ptr<UsbService> UsbService::Create() {
 #if BUILDFLAG(IS_ANDROID)
   return base::WrapUnique(new UsbServiceAndroid());
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
   return base::WrapUnique(new UsbServiceLinux());
 #elif BUILDFLAG(IS_WIN)
   return base::WrapUnique(new UsbServiceWin());
 #elif BUILDFLAG(IS_MAC)
+  return base::WrapUnique(new UsbServiceImpl());
+#elif BUILDFLAG(IS_BSD)
   return base::WrapUnique(new UsbServiceImpl());
 #else
   return nullptr;
