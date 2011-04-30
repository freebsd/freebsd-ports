--- chrome/common/service_process_util_posix.h.orig	2011-04-21 20:57:02.534558581 +0300
+++ chrome/common/service_process_util_posix.h	2011-04-21 20:57:16.326558123 +0300
@@ -14,10 +14,10 @@
 #include "base/message_pump_libevent.h"
 #include "base/scoped_ptr.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/common/multi_process_lock.h"
 MultiProcessLock* TakeServiceRunningLock(bool waiting);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 
 #if defined(OS_MACOSX)
 #include "base/mac/scoped_cftyperef.h"
@@ -65,10 +65,10 @@
   FilePathWatcher executable_watcher_;
   ServiceProcessState* state_;
 #endif  // OS_MACOSX
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   scoped_ptr<MultiProcessLock> initializing_lock_;
   scoped_ptr<MultiProcessLock> running_lock_;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
   scoped_ptr<ServiceProcessShutdownMonitor> shut_down_monitor_;
   base::MessagePumpLibevent::FileDescriptorWatcher watcher_;
   int sockets_[2];
