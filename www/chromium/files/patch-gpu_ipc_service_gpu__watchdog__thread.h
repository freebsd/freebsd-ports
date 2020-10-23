--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2020-09-08 19:14:06 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -213,7 +213,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   base::ThreadTicks GetWatchedThreadTime();
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   void UpdateActiveTTY();
 #endif
 
@@ -261,7 +261,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   base::Time check_time_;
   base::TimeTicks check_timeticks_;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
   int active_tty_ = -1;
