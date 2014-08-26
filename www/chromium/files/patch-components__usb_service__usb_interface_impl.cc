--- ./components/usb_service/usb_interface_impl.cc.orig	2014-08-20 21:02:55.000000000 +0200
+++ ./components/usb_service/usb_interface_impl.cc	2014-08-22 15:06:25.000000000 +0200
@@ -5,7 +5,11 @@
 #include "components/usb_service/usb_interface_impl.h"
 
 #include "base/logging.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
