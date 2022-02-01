--- base/debug/stack_trace.h.orig	2021-12-14 11:44:55 UTC
+++ base/debug/stack_trace.h
@@ -18,6 +18,7 @@
 #if !defined(OS_NACL)
 #include <signal.h>
 #endif
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
@@ -155,7 +156,7 @@ BASE_EXPORT size_t CollectStackTrace(void** trace, siz
 // scanning area at the origin of the stack, wasting time and not finding any
 // frames (since Android libraries don't have frame pointers). Scanning is not
 // enabled on other posix platforms due to legacy reasons.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 constexpr bool kEnableScanningByDefault = true;
 #else
 constexpr bool kEnableScanningByDefault = false;
