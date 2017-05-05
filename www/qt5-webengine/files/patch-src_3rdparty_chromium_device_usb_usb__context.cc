--- src/3rdparty/chromium/device/usb/usb_context.cc.orig	2017-04-11 14:15:58 UTC
+++ src/3rdparty/chromium/device/usb/usb_context.cc
@@ -9,8 +9,7 @@
 #include "base/macros.h"
 #include "base/threading/simple_thread.h"
 #include "device/usb/usb_error.h"
-#include "third_party/libusb/src/libusb/interrupt.h"
-#include "third_party/libusb/src/libusb/libusb.h"
+#include "libusb.h"
 
 namespace device {
 
@@ -58,7 +57,9 @@ void UsbContext::UsbEventHandler::Run() {
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(__FreeBSD__)
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
