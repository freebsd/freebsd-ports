--- base/tracing/trace_time.h.orig	2022-02-07 13:39:41 UTC
+++ base/tracing/trace_time.h
@@ -12,7 +12,7 @@ namespace base {
 namespace tracing {
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::BuiltinClock kTraceClockId =
