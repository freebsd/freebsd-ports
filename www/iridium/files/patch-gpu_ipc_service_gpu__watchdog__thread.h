--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2020-03-16 18:40:32 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -207,7 +207,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   base::ThreadTicks GetWatchedThreadTime();
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   void UpdateActiveTTY();
 #endif
 
@@ -265,7 +265,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   // whether GpuWatchdogThreadEvent::kGpuWatchdogStart has been recorded.
   bool is_watchdog_start_histogram_recorded = false;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
   int active_tty_ = -1;
