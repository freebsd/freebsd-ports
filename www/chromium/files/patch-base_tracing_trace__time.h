--- base/tracing/trace_time.h.orig	2021-07-21 13:25:51 UTC
+++ base/tracing/trace_time.h
@@ -11,7 +11,7 @@
 namespace base {
 namespace tracing {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
