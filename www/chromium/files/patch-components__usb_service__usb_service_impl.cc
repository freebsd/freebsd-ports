--- ./components/usb_service/usb_service_impl.cc.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service/usb_service_impl.cc	2014-08-13 09:56:57.000000000 +0200
@@ -13,7 +13,11 @@
 #include "components/usb_service/usb_context.h"
 #include "components/usb_service/usb_device_impl.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
