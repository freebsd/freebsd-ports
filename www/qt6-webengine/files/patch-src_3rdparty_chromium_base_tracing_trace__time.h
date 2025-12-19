--- src/3rdparty/chromium/base/tracing/trace_time.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/tracing/trace_time.h
@@ -12,7 +12,7 @@ namespace tracing {
 namespace tracing {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::BuiltinClock kTraceClockId =
