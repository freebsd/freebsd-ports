--- src/3rdparty/chromium/device/usb/usb_context.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/device/usb/usb_context.cc
@@ -58,7 +58,9 @@ void UsbContext::UsbEventHandler::Run() {
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
