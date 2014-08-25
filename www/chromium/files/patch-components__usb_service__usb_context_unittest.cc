--- ./components/usb_service/usb_context_unittest.cc.orig	2014-08-20 21:02:55.000000000 +0200
+++ ./components/usb_service/usb_context_unittest.cc	2014-08-22 15:06:25.000000000 +0200
@@ -6,7 +6,11 @@
 #include "build/build_config.h"
 #include "components/usb_service/usb_context.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 using usb_service::UsbContext;
 using usb_service::PlatformUsbContext;
