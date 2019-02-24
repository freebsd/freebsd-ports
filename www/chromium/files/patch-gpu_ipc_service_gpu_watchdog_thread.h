--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2019-01-12 22:38:38.703173000 +0100
+++ gpu/ipc/service/gpu_watchdog_thread.h	2019-01-12 22:39:05.661205000 +0100
@@ -190,8 +190,10 @@
   XDisplay* display_;
   gfx::AcceleratedWidget window_;
   XAtom atom_;
+#if !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
+#endif
 #endif
 
   base::RepeatingClosure alternative_terminate_for_testing_;
