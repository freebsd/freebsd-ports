--- src/3rdparty/chromium/base/message_loop/message_pump_glib.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/message_loop/message_pump_glib.cc
@@ -8,6 +8,11 @@
 #include <glib.h>
 #include <math.h>
 
+#if BUILDFLAG(IS_BSD)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #include "base/logging.h"
 #include "base/memory/raw_ptr.h"
 #include "base/notreached.h"
@@ -52,9 +57,13 @@ bool RunningOnMainThread() {
 }
 
 bool RunningOnMainThread() {
+#if BUILDFLAG(IS_BSD)
+  return pthread_main_np();
+#else
   auto pid = getpid();
   auto tid = PlatformThread::CurrentId();
   return pid > 0 && tid > 0 && pid == tid;
+#endif
 }
 
 // A brief refresher on GLib:
