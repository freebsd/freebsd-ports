--- ./third_party/libjingle/source/talk/base/cpumonitor.cc.orig	2014-08-20 21:03:47.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/cpumonitor.cc	2014-08-22 15:06:26.000000000 +0200
@@ -53,13 +53,13 @@
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
@@ -285,6 +285,11 @@
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
@@ -359,7 +364,7 @@
       TimeValueTToInt64(task_term_info.system_time));
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
   rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0) {
     LOG_ERR(LS_ERROR) << "getrusage failed";
@@ -369,7 +374,7 @@
   const uint64 cpu_times =
       (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * kNumMicrosecsPerSec +
       usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
 
 #if defined(__native_client__)
   // TODO(ryanpetrie): Implement this via PPAPI when it's available.
