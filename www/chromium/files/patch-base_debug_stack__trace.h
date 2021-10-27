--- base/debug/stack_trace.h.orig	2021-09-24 04:25:55 UTC
+++ base/debug/stack_trace.h
@@ -19,6 +19,7 @@
 #if !defined(OS_NACL)
 #include <signal.h>
 #endif
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
@@ -156,7 +157,7 @@ BASE_EXPORT size_t CollectStackTrace(void** trace, siz
 // scanning area at the origin of the stack, wasting time and not finding any
 // frames (since Android libraries don't have frame pointers). Scanning is not
 // enabled on other posix platforms due to legacy reasons.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 constexpr bool kEnableScanningByDefault = true;
 #else
 constexpr bool kEnableScanningByDefault = false;
