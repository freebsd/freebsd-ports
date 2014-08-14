--- ./components/usb_service/usb_context.cc.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service/usb_context.cc	2014-08-13 09:56:57.000000000 +0200
@@ -7,8 +7,13 @@
 #include "base/logging.h"
 #include "base/synchronization/waitable_event.h"
 #include "base/threading/platform_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/interrupt.h"
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace usb_service {
 
@@ -45,7 +50,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD) // XXX(rene) only available in bundled version
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
