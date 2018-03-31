--- device/usb/usb_device_handle_impl.cc.orig	2018-03-20 23:05:25.000000000 +0100
+++ device/usb/usb_device_handle_impl.cc	2018-03-24 17:28:45.532305000 +0100
@@ -25,7 +25,11 @@
 #include "device/usb/usb_device_impl.h"
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
