--- ./third_party/libjingle/source/talk/base/cpumonitor.cc.orig	2014-04-30 22:44:03.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/cpumonitor.cc	2014-05-04 14:38:48.000000000 +0200
@@ -52,13 +52,13 @@
 #include <mach/task.h>
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <sys/resource.h>
 #include <errno.h>
 #include <stdio.h>
 #include "talk/base/fileutils.h"
 #include "talk/base/pathutils.h"
-#endif // defined(LINUX) || defined(ANDROID)
+#endif // defined(LINUX) || defined(ANDROID) || defined(BSD)
 
 #if defined(IOS) || defined(OSX)
 static uint64 TimeValueTToInt64(const time_value_t &time_value) {
@@ -281,6 +281,11 @@
   const uint64 cpu_times = nice + system + user;
   const uint64 total_times = cpu_times + idle;
 #endif  // defined(LINUX) || defined(ANDROID)
+#if defined(BSD)
+  const uint64 cpu_times = 0;
+  const uint64 total_times = 0;
+  return 0.f;
+#endif
 
 #if defined(__native_client__)
   // TODO(ryanpetrie): Implement this via PPAPI when it's available.
@@ -355,7 +360,7 @@
       TimeValueTToInt64(task_term_info.system_time));
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
   rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0) {
     LOG_ERR(LS_ERROR) << "getrusage failed";
@@ -365,7 +370,7 @@
   const uint64 cpu_times =
       (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * kNumMicrosecsPerSec +
       usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
 
 #if defined(__native_client__)
   // TODO(ryanpetrie): Implement this via PPAPI when it's available.
