--- base/message_loop/message_pump_glib.cc.orig	2026-08-13 07:41:05 UTC
+++ base/message_loop/message_pump_glib.cc
@@ -7,6 +7,11 @@
 #include <fcntl.h>
 #include <glib.h>
 
+#if BUILDFLAG(IS_BSD)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #include "base/logging.h"
 #include "base/memory/raw_ptr.h"
 #include "base/message_loop/io_watcher.h"
@@ -58,9 +63,13 @@ int GetTimeIntervalMilliseconds(TimeTicks next_task_ti
 }
 
 bool RunningOnMainThread() {
+#if BUILDFLAG(IS_BSD)
+  return pthread_main_np();
+#else
   pid_t pid = getpid();
   pid_t tid = PlatformThread::CurrentId().raw();
   return pid > 0 && tid > 0 && pid == tid;
+#endif
 }
 
 // A brief refresher on GLib:
