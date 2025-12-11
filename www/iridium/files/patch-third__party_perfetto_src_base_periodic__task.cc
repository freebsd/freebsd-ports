--- third_party/perfetto/src/base/periodic_task.cc.orig	2025-12-10 15:04:57 UTC
+++ third_party/perfetto/src/base/periodic_task.cc
@@ -24,7 +24,7 @@
 #include "perfetto/base/time.h"
 #include "perfetto/ext/base/file_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
 #include <sys/timerfd.h>
 #endif
@@ -44,7 +44,7 @@ uint32_t GetNextDelayMs(const TimeMillis& now_ms,
 }
 
 ScopedPlatformHandle CreateTimerFd(const PeriodicTask::Args& args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
   ScopedPlatformHandle tfd(
       timerfd_create(CLOCK_BOOTTIME, TFD_CLOEXEC | TFD_NONBLOCK));
