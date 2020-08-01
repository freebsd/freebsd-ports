--- services/tracing/public/cpp/perfetto/trace_time.cc.orig	2020-07-07 21:57:41 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,13 +12,17 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   struct timespec ts;
+#if defined(OS_BSD)
+  int res = clock_gettime(CLOCK_UPTIME, &ts);
+#else
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#endif
   if (res != -1)
     return static_cast<int64_t>(perfetto::base::FromPosixTimespec(ts).count());
 #endif
   return TRACE_TIME_TICKS_NOW().since_origin().InNanoseconds();
 }
 
-}  // namespace tracing
\ No newline at end of file
+}  // namespace tracing
