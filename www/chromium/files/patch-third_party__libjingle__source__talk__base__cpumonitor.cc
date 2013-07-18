--- third_party/libjingle/source/talk/base/cpumonitor.cc.orig	2013-07-15 17:23:44.000000000 +0300
+++ third_party/libjingle/source/talk/base/cpumonitor.cc	2013-07-15 17:34:46.000000000 +0300
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
@@ -281,12 +281,16 @@
   const uint64 cpu_times = nice + system + user;
   const uint64 total_times = cpu_times + idle;
 #endif  // defined(LINUX) || defined(ANDROID)
+#if defined(BSD)
+  return 0.f;
+#else
   system_.prev_load_time_ = timenow;
   system_.prev_load_ = UpdateCpuLoad(total_times,
                                      cpu_times * cpus_,
                                      &system_.prev_total_times_,
                                      &system_.prev_cpu_times_);
   return system_.prev_load_;
+#endif
 }
 
 float CpuSampler::GetProcessLoad() {
@@ -348,7 +352,7 @@
       TimeValueTToInt64(task_term_info.system_time));
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
   rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0) {
     LOG_ERR(LS_ERROR) << "getrusage failed";
@@ -358,7 +362,7 @@
   const uint64 cpu_times =
       (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * kNumMicrosecsPerSec +
       usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
   process_.prev_load_time_ = timenow;
   process_.prev_load_ = UpdateCpuLoad(total_times,
                                      cpu_times,
