--- third_party/perfetto/src/base/periodic_task.cc.orig	2026-01-16 13:40:34 UTC
+++ third_party/perfetto/src/base/periodic_task.cc
@@ -24,9 +24,10 @@
 #include "perfetto/base/time.h"
 #include "perfetto/ext/base/file_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) ||           \
-    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
 #include <sys/timerfd.h>
 #endif
 
@@ -45,9 +46,10 @@ uint32_t GetNextDelayMs(const TimeMillis& now_ms,
 }
 
 ScopedPlatformHandle CreateTimerFd(const PeriodicTask::Args& args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) ||           \
-    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
   ScopedPlatformHandle tfd(
       timerfd_create(CLOCK_BOOTTIME, TFD_CLOEXEC | TFD_NONBLOCK));
   uint32_t phase_ms = GetNextDelayMs(GetBootTimeMs(), args);
