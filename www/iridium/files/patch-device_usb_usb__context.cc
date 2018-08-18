--- device/usb/usb_context.cc.orig	2018-06-13 00:10:18.000000000 +0200
+++ device/usb/usb_context.cc	2018-07-20 12:52:29.240720000 +0200
@@ -58,7 +58,9 @@
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
