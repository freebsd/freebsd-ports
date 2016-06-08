--- ./chrome/browser/usb/usb_context.cc.orig	2014-04-30 22:42:13.000000000 +0200
+++ ./chrome/browser/usb/usb_context.cc	2014-05-04 14:38:46.000000000 +0200
@@ -43,7 +43,9 @@
   running_ = false;
   // Spreading running_ to the UsbEventHandler thread.
   base::subtle::MemoryBarrier();
+#if !defined(OS_FREEBSD)
   libusb_interrupt_handle_event(context_);
+#endif
   base::PlatformThread::Join(thread_handle_);
 }
 
