--- device/usb/usb_device_impl.cc.orig	2017-07-25 21:04:56.000000000 +0200
+++ device/usb/usb_device_impl.cc	2017-08-02 13:51:03.580494000 +0200
@@ -24,7 +24,11 @@
 #include "device/usb/usb_device_handle_impl.h"
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
