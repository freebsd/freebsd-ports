--- gpu/ipc/service/gpu_watchdog_thread.cc.orig	2019-06-04 18:55:24 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.cc
@@ -54,8 +54,10 @@ const int kGpuTimeout = 10000;
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
+#endif
 const unsigned char text[20] = "check";
 #endif
 
@@ -78,8 +80,10 @@ GpuWatchdogThread::GpuWatchdogThread()
       display_(nullptr),
       window_(0),
       atom_(x11::None),
+#if !defined(OS_BSD)
       host_tty_(-1),
 #endif
+#endif
       weak_factory_(this) {
   base::subtle::NoBarrier_Store(&awaiting_acknowledge_, false);
 
@@ -94,7 +98,9 @@ GpuWatchdogThread::GpuWatchdogThread()
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
+#endif
   SetupXServer();
 #endif
   base::MessageLoopCurrent::Get()->AddTaskObserver(&task_observer_);
@@ -242,8 +248,10 @@ GpuWatchdogThread::~GpuWatchdogThread() {
     power_monitor->RemoveObserver(this);
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
+#endif
   if (display_) {
     DCHECK(window_);
     XDestroyWindow(display_, window_);
@@ -467,7 +475,7 @@ void GpuWatchdogThread::DeliberatelyTerminateToRecover
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   int active_tty = GetActiveTTY();
   if (host_tty_ != -1 && active_tty != -1 && host_tty_ != active_tty) {
@@ -554,7 +562,9 @@ void GpuWatchdogThread::SetupXServer() {
                       CopyFromParent, InputOutput, CopyFromParent, 0, nullptr);
     atom_ = XInternAtom(display_, "CHECK", x11::False);
   }
+#if !defined(OS_BSD)
   host_tty_ = GetActiveTTY();
+#endif
 }
 
 void GpuWatchdogThread::SetupXChangeProp() {
@@ -657,7 +667,7 @@ base::ThreadTicks GpuWatchdogThread::GetWatchedThreadT
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 int GpuWatchdogThread::GetActiveTTY() const {
   char tty_string[8] = {0};
   if (tty_file_ && !fseek(tty_file_, 0, SEEK_SET) &&
