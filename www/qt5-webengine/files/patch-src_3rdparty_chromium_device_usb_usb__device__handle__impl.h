--- src/3rdparty/chromium/device/usb/usb_device_handle_impl.h.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/usb/usb_device_handle_impl.h
@@ -18,7 +18,12 @@
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
