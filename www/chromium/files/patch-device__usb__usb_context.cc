--- device/usb/usb_context.cc.orig	2015-07-15 16:30:04.000000000 -0400
+++ device/usb/usb_context.cc	2015-07-22 07:32:40.938868000 -0400
@@ -8,8 +8,13 @@
 #include "base/logging.h"
 #include "base/threading/platform_thread.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/interrupt.h"
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
@@ -62,7 +67,9 @@
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
