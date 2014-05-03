--- ./chrome/browser/usb/usb_context.cc.orig	2014-04-24 22:35:11.000000000 +0200
+++ ./chrome/browser/usb/usb_context.cc	2014-04-24 23:23:43.000000000 +0200
@@ -43,7 +43,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD)
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
