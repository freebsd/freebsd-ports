--- src/3rdparty/chromium/device/usb/usb_error.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/usb/usb_error.cc
@@ -4,7 +4,11 @@
 
 #include "device/usb/usb_error.h"
 
+#if defined(__FreeBSD__)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
