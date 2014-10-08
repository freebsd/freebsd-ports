--- components/usb_service/usb_context.cc.orig	2014-10-02 17:39:47 UTC
+++ components/usb_service/usb_context.cc
@@ -8,8 +8,13 @@
 #include "base/synchronization/waitable_event.h"
 #include "base/threading/platform_thread.h"
 #include "components/usb_service/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/interrupt.h"
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
@@ -46,7 +51,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD) // XXX(rene) only available in bundled version
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
