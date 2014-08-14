--- ./components/usb_service/usb_interface.cc.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service/usb_interface.cc	2014-08-13 09:56:57.000000000 +0200
@@ -5,7 +5,11 @@
 #include "components/usb_service/usb_interface.h"
 
 #include "base/logging.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
