--- src/3rdparty/chromium/base/message_loop/message_pump_glib.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/message_loop/message_pump_glib.cc
@@ -8,6 +8,11 @@
 #include <glib.h>
 #include <math.h>
 
+#if defined(OS_BSD)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #include "base/logging.h"
 #include "base/numerics/safe_conversions.h"
 #include "base/posix/eintr_wrapper.h"
@@ -48,9 +53,13 @@ bool RunningOnMainThread() {
 }
 
 bool RunningOnMainThread() {
+#if defined(OS_BSD)
+  return pthread_main_np();
+#else
   auto pid = getpid();
   auto tid = PlatformThread::CurrentId();
   return pid > 0 && tid > 0 && pid == tid;
+#endif
 }
 
 // A brief refresher on GLib:
