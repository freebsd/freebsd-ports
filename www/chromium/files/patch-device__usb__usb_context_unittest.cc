--- device/usb/usb_context_unittest.cc.orig	2014-10-10 08:54:15 UTC
+++ device/usb/usb_context_unittest.cc
@@ -6,7 +6,11 @@
 #include "build/build_config.h"
 #include "device/usb/usb_context.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
