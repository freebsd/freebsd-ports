--- components/usb_service/usb_device_impl.cc.orig	2014-10-02 17:39:47 UTC
+++ components/usb_service/usb_device_impl.cc
@@ -12,7 +12,11 @@
 #include "components/usb_service/usb_error.h"
 #include "components/usb_service/usb_interface_impl.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_CHROMEOS)
 #include "base/sys_info.h"
