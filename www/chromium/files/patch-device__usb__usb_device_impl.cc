--- device/usb/usb_device_impl.cc.orig	2014-10-10 08:54:15 UTC
+++ device/usb/usb_device_impl.cc
@@ -17,7 +17,11 @@
 #include "device/usb/usb_descriptors.h"
 #include "device/usb/usb_device_handle_impl.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_CHROMEOS)
 #include "base/sys_info.h"
