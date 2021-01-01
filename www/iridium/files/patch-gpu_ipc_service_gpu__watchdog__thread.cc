--- gpu/ipc/service/gpu_watchdog_thread.cc.orig	2020-03-16 18:40:32 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.cc
@@ -63,7 +63,7 @@ void GpuWatchdogTimeoutHistogram(GpuWatchdogTimeoutEve
   base::UmaHistogramEnumeration("GPU.WatchdogThread.V1.Timeout", timeout_event);
 }
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
 #endif
@@ -81,7 +81,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
       arm_cpu_time_(),
 #endif
       suspension_counter_(this)
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
       ,
       host_tty_(-1)
 #endif
@@ -103,7 +103,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
   DCHECK(result);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
   UpdateActiveTTY();
   host_tty_ = active_tty_;
@@ -251,7 +251,7 @@ GpuWatchdogThreadImplV1::~GpuWatchdogThreadImplV1() {
 
   base::PowerMonitor::RemoveObserver(this);
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -434,7 +434,7 @@ void GpuWatchdogThreadImplV1::DeliberatelyTerminateToR
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   UpdateActiveTTY();
   if (host_tty_ != -1 && active_tty_ != -1 && host_tty_ != active_tty_) {
@@ -609,7 +609,7 @@ base::ThreadTicks GpuWatchdogThreadImplV1::GetWatchedT
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 void GpuWatchdogThreadImplV1::UpdateActiveTTY() {
   last_active_tty_ = active_tty_;
 
