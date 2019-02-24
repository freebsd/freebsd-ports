--- gpu/ipc/service/gpu_watchdog_thread.cc.orig	2019-01-12 22:38:32.375483000 +0100
+++ gpu/ipc/service/gpu_watchdog_thread.cc	2019-01-12 22:42:03.901161000 +0100
@@ -46,8 +46,10 @@
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
+#endif
 const unsigned char text[20] = "check";
 #endif
 
@@ -70,8 +72,10 @@
       display_(nullptr),
       window_(0),
       atom_(x11::None),
+#if !defined(OS_BSD)
       host_tty_(-1),
 #endif
+#endif
       weak_factory_(this) {
   base::subtle::NoBarrier_Store(&awaiting_acknowledge_, false);
 
@@ -86,7 +90,9 @@
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
+#endif
   SetupXServer();
 #endif
   watched_message_loop_->AddTaskObserver(&task_observer_);
@@ -231,8 +237,10 @@
     power_monitor->RemoveObserver(this);
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
+#endif
   if (display_) {
     DCHECK(window_);
     XDestroyWindow(display_, window_);
@@ -453,7 +461,7 @@
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   int active_tty = GetActiveTTY();
   if (host_tty_ != -1 && active_tty != -1 && host_tty_ != active_tty) {
@@ -516,7 +524,9 @@
                       CopyFromParent, InputOutput, CopyFromParent, 0, nullptr);
     atom_ = XInternAtom(display_, "CHECK", x11::False);
   }
+#if !defined(OS_BSD)
   host_tty_ = GetActiveTTY();
+#endif
 }
 
 void GpuWatchdogThread::SetupXChangeProp() {
@@ -617,7 +627,7 @@
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 int GpuWatchdogThread::GetActiveTTY() const {
   char tty_string[8] = {0};
   if (tty_file_ && !fseek(tty_file_, 0, SEEK_SET) &&
