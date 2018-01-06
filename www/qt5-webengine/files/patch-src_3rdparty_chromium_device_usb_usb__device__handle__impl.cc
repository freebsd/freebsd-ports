--- src/3rdparty/chromium/device/usb/usb_device_handle_impl.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/usb/usb_device_handle_impl.cc
@@ -25,7 +25,11 @@
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
 #include "net/base/io_buffer.h"
-#include "third_party/libusb/src/libusb/libusb.h"
+#if defined(OS_FREEBSD)
+#  include "libusb.h"
+#else
+#  include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
