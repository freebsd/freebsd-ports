--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2021-04-14 18:41:04 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -198,7 +198,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThread : publi
   bool WithinOneMinFromPowerResumed();
   bool WithinOneMinFromForegrounded();
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   void UpdateActiveTTY();
 #endif
   // The watchdog continues when it's not on the TTY of our host X11 server.
@@ -270,7 +270,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThread : publi
   bool less_than_full_thread_time_after_capped_ = false;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_ = nullptr;
   int host_tty_ = -1;
   int active_tty_ = -1;
