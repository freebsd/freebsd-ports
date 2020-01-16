--- gpu/ipc/service/gpu_watchdog_thread.cc.orig	2019-12-16 21:51:26 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.cc
@@ -40,7 +40,7 @@ const int kGpuTimeout = 15000;
 const int kGpuTimeout = 10000;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
 #endif
@@ -59,7 +59,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
       arm_cpu_time_(),
 #endif
       suspension_counter_(this)
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
       ,
       host_tty_(-1)
 #endif
@@ -76,7 +76,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
   DCHECK(result);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
   host_tty_ = GetActiveTTY();
 #endif
@@ -222,7 +222,7 @@ GpuWatchdogThreadImplV1::~GpuWatchdogThreadImplV1() {
 
   base::PowerMonitor::RemoveObserver(this);
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -371,7 +371,7 @@ void GpuWatchdogThreadImplV1::DeliberatelyTerminateToR
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   int active_tty = GetActiveTTY();
   if (host_tty_ != -1 && active_tty != -1 && host_tty_ != active_tty) {
@@ -528,7 +528,7 @@ base::ThreadTicks GpuWatchdogThreadImplV1::GetWatchedT
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 int GpuWatchdogThreadImplV1::GetActiveTTY() const {
   char tty_string[8] = {0};
   if (tty_file_ && !fseek(tty_file_, 0, SEEK_SET) &&
