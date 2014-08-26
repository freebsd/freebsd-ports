--- ./components/usb_service/usb_device_impl.cc.orig	2014-08-20 21:02:55.000000000 +0200
+++ ./components/usb_service/usb_device_impl.cc	2014-08-22 15:06:25.000000000 +0200
@@ -12,7 +12,11 @@
 #include "components/usb_service/usb_error.h"
 #include "components/usb_service/usb_interface_impl.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_CHROMEOS)
 #include "base/sys_info.h"
