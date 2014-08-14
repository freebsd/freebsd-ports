--- ./components/usb_service/usb_device_handle.cc.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service/usb_device_handle.cc	2014-08-13 09:56:57.000000000 +0200
@@ -16,7 +16,12 @@
 #include "components/usb_service/usb_interface.h"
 #include "components/usb_service/usb_service.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 using content::BrowserThread;
 
