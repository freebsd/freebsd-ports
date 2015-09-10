--- device/usb/usb_device_handle_impl.h.orig	2015-07-15 16:30:04.000000000 -0400
+++ device/usb/usb_device_handle_impl.h	2015-07-22 07:35:03.384188000 -0400
@@ -13,7 +13,12 @@
 #include "base/memory/ref_counted.h"
 #include "base/threading/thread_checker.h"
 #include "device/usb/usb_device_handle.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace base {
 class SequencedTaskRunner;
