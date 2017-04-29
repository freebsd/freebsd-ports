--- device/usb/usb_context.cc.orig	2017-04-19 19:06:34 UTC
+++ device/usb/usb_context.cc
@@ -9,8 +9,13 @@
 #include "base/macros.h"
 #include "base/threading/simple_thread.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/interrupt.h"
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
@@ -58,7 +63,9 @@ void UsbContext::UsbEventHandler::Run() 
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
