--- services/device/usb/usb_service.cc.orig	2022-10-29 17:50:56 UTC
+++ services/device/usb/usb_service.cc
@@ -29,6 +29,10 @@
 #include "services/device/usb/usb_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/usb/usb_service_win.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/usb/usb_service_impl.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/usb/usb_service_fake.h"
 #endif
 
 namespace device {
@@ -60,6 +64,8 @@ std::unique_ptr<UsbService> UsbService::Create() {
     return base::WrapUnique(new UsbServiceMac());
   else
     return base::WrapUnique(new UsbServiceImpl());
+#elif BUILDFLAG(IS_BSD)
+  return base::WrapUnique(new UsbServiceImpl());
 #else
   return nullptr;
 #endif
