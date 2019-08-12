--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2019-07-24 18:58:27 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -191,8 +191,10 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThread : publi
   XDisplay* display_;
   gfx::AcceleratedWidget window_;
   XAtom atom_;
+#if !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
+#endif
 #endif
 
   base::RepeatingClosure alternative_terminate_for_testing_;
