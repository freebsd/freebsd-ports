--- src/3rdparty/chromium/base/message_loop/message_pump_glib.cc.orig	2022-09-26 10:05:50 UTC
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
 #include "base/notreached.h"
 #include "base/numerics/safe_conversions.h"
@@ -50,9 +55,13 @@ bool RunningOnMainThread() {
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
