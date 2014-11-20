--- third_party/webrtc/base/cpumonitor.cc.orig	2014-10-10 09:16:13 UTC
+++ third_party/webrtc/base/cpumonitor.cc
@@ -36,13 +36,13 @@
 #include <mach/task.h>
 #endif  // defined(WEBRTC_MAC)
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <sys/resource.h>
 #include <errno.h>
 #include <stdio.h>
 #include "webrtc/base/fileutils.h"
 #include "webrtc/base/pathutils.h"
-#endif // defined(WEBRTC_LINUX)
+#endif // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 
 #if defined(WEBRTC_MAC)
 static uint64 TimeValueTToInt64(const time_value_t &time_value) {
@@ -342,7 +342,7 @@
       TimeValueTToInt64(task_term_info.system_time));
 #endif  // defined(WEBRTC_MAC)
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0) {
     LOG_ERR(LS_ERROR) << "getrusage failed";
@@ -352,7 +352,7 @@
   const uint64 cpu_times =
       (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * kNumMicrosecsPerSec +
       usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 
 #if defined(__native_client__)
   // TODO(ryanpetrie): Implement this via PPAPI when it's available.
