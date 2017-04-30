--- device/usb/usb_device_impl.cc.orig	2017-04-19 19:06:34 UTC
+++ device/usb/usb_device_impl.cc
@@ -22,7 +22,11 @@
 #include "device/usb/usb_descriptors.h"
 #include "device/usb/usb_device_handle_impl.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
