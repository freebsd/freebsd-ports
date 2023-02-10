--- src/3rdparty/chromium/base/tracing/trace_time.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/tracing/trace_time.cc
@@ -8,13 +8,17 @@
 #include "build/build_config.h"
 #include "third_party/perfetto/include/perfetto/base/time.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#define CLOCK_BOOTTIME CLOCK_UPTIME
+#endif
+
 namespace base {
 namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
   if (res != -1)
@@ -24,4 +28,4 @@ int64_t TraceBootTicksNow() {
 }
 
 }  // namespace tracing
-}  // namespace base
\ No newline at end of file
+}  // namespace base
