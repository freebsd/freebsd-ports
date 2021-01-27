--- gpu/ipc/service/gpu_watchdog_thread.cc.orig	2021-01-18 21:28:59 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.cc
@@ -77,7 +77,7 @@ GpuWatchdogThread::GpuWatchdogThread(base::TimeDelta t
   }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(
       base::FilePath(FILE_PATH_LITERAL("/sys/class/tty/tty0/active")), "r");
   UpdateActiveTTY();
@@ -105,7 +105,7 @@ GpuWatchdogThread::~GpuWatchdogThread() {
     CloseHandle(watched_thread_handle_);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -476,7 +476,7 @@ void GpuWatchdogThread::OnWatchdogTimeout() {
   if (foregrounded_event_)
     num_of_timeout_after_foregrounded_++;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   UpdateActiveTTY();
 #endif
 
@@ -869,7 +869,7 @@ bool GpuWatchdogThread::WithinOneMinFromForegrounded()
   return foregrounded_event_ && num_of_timeout_after_foregrounded_ <= count;
 }
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 void GpuWatchdogThread::UpdateActiveTTY() {
   last_active_tty_ = active_tty_;
 
@@ -886,7 +886,7 @@ void GpuWatchdogThread::UpdateActiveTTY() {
 #endif
 
 bool GpuWatchdogThread::ContinueOnNonHostX11ServerTty() {
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (host_tty_ == -1 || active_tty_ == -1)
     return false;
 
