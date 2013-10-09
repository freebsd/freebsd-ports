--- chrome/browser/usb/usb_context.cc.orig	2013-10-08 21:07:13.000000000 +0300
+++ chrome/browser/usb/usb_context.cc	2013-10-08 22:04:50.000000000 +0300
@@ -44,7 +44,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD)
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
