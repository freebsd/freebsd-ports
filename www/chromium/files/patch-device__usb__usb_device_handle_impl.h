--- device/usb/usb_device_handle_impl.h.orig	2014-10-10 09:15:31 UTC
+++ device/usb/usb_device_handle_impl.h
@@ -14,7 +14,12 @@
 #include "base/threading/thread_checker.h"
 #include "device/usb/usb_device_handle.h"
 #include "net/base/io_buffer.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace base {
 class SingleThreadTaskRunner;
