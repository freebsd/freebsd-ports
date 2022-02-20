--- base/tracing/trace_time.cc.orig	2022-02-07 13:39:41 UTC
+++ base/tracing/trace_time.cc
@@ -8,13 +8,17 @@
 #include "build/build_config.h"
 #include "third_party/perfetto/include/perfetto/base/time.h"
 
+#if defined(OS_FREEBSD)
+#define CLOCK_BOOTTIME CLOCK_UPTIME
+#endif
+
 namespace base {
 namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
   if (res != -1)
@@ -24,4 +28,4 @@ int64_t TraceBootTicksNow() {
 }
 
 }  // namespace tracing
-}  // namespace base
\ No newline at end of file
+}  // namespace base
