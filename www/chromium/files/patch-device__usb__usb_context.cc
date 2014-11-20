--- device/usb/usb_context.cc.orig	2014-10-10 09:15:31 UTC
+++ device/usb/usb_context.cc
@@ -9,8 +9,13 @@
 #include "base/synchronization/waitable_event.h"
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
 
@@ -43,7 +48,9 @@
 
 UsbContext::UsbEventHandler::~UsbEventHandler() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
