--- device/usb/usb_device_handle_impl.cc.orig	2014-10-10 08:54:15 UTC
+++ device/usb/usb_device_handle_impl.cc
@@ -19,7 +19,12 @@
 #include "device/usb/usb_device_impl.h"
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
