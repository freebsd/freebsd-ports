--- base/tracing/trace_time.cc.orig	2021-07-21 11:24:56 UTC
+++ base/tracing/trace_time.cc
@@ -16,7 +16,11 @@ int64_t TraceBootTicksNow() {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
     defined(OS_FUCHSIA)
   struct timespec ts;
+#if defined(OS_BSD)
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#else
+  int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#endif
   if (res != -1)
     return static_cast<int64_t>(perfetto::base::FromPosixTimespec(ts).count());
 #endif
