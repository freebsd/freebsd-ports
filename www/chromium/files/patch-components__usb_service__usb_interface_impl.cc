--- components/usb_service/usb_interface_impl.cc.orig	2014-10-02 17:39:47 UTC
+++ components/usb_service/usb_interface_impl.cc
@@ -5,7 +5,11 @@
 #include "components/usb_service/usb_interface_impl.h"
 
 #include "base/logging.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
