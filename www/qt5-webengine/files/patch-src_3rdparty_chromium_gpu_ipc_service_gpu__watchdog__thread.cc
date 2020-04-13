--- src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc
@@ -45,8 +45,10 @@ const int kGpuTimeout = 10000;
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
+#endif
 const unsigned char text[20] = "check";
 #endif
 
@@ -68,9 +70,12 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
       ,
       display_(nullptr),
       window_(0),
-      atom_(x11::None),
+      atom_(x11::None)
+#if !defined(OS_BSD)
+      ,
       host_tty_(-1)
 #endif
+#endif
 {
   base::subtle::NoBarrier_Store(&awaiting_acknowledge_, false);
 
@@ -85,7 +90,9 @@ GpuWatchdogThreadImplV1::GpuWatchdogThreadImplV1()
 #endif
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
+#endif
   SetupXServer();
 #endif
   base::MessageLoopCurrent::Get()->AddTaskObserver(&task_observer_);
@@ -230,8 +237,10 @@ GpuWatchdogThreadImplV1::~GpuWatchdogThreadImplV1() {
   base::PowerMonitor::RemoveObserver(this);
 
 #if defined(USE_X11)
+#if !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
+#endif
   if (display_) {
     DCHECK(window_);
     XDestroyWindow(display_, window_);
@@ -431,7 +440,7 @@ void GpuWatchdogThreadImplV1::DeliberatelyTerminateToR
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   int active_tty = GetActiveTTY();
   if (host_tty_ != -1 && active_tty != -1 && host_tty_ != active_tty) {
@@ -515,7 +524,9 @@ void GpuWatchdogThreadImplV1::SetupXServer() {
                       CopyFromParent, InputOutput, CopyFromParent, 0, nullptr);
     atom_ = XInternAtom(display_, "CHECK", x11::False);
   }
+#if !defined(OS_BSD)
   host_tty_ = GetActiveTTY();
+#endif
 }
 
 void GpuWatchdogThreadImplV1::SetupXChangeProp() {
@@ -615,7 +626,7 @@ base::ThreadTicks GpuWatchdogThreadImplV1::GetWatchedT
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 int GpuWatchdogThreadImplV1::GetActiveTTY() const {
   char tty_string[8] = {0};
   if (tty_file_ && !fseek(tty_file_, 0, SEEK_SET) &&
