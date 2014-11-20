--- device/usb/usb_service_impl.cc.orig	2014-10-10 09:15:31 UTC
+++ device/usb/usb_service_impl.cc
@@ -14,7 +14,11 @@
 #include "device/usb/usb_context.h"
 #include "device/usb/usb_device_impl.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
