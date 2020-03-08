--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2020-03-03 18:53:55 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -181,7 +181,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   base::ThreadTicks GetWatchedThreadTime();
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   int GetActiveTTY() const;
 #endif
 
@@ -232,7 +232,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   // whether GpuWatchdogThreadEvent::kGpuWatchdogStart has been recorded.
   bool is_watchdog_start_histogram_recorded = false;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
 #endif
