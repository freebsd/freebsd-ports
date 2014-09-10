--- ./components/usb_service/usb_error.cc.orig	2014-08-20 21:02:55.000000000 +0200
+++ ./components/usb_service/usb_error.cc	2014-08-23 00:55:43.000000000 +0200
@@ -4,7 +4,11 @@
 
 #include "components/usb_service/usb_error.h"
 
+#if defined(__FreeBSD__)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
