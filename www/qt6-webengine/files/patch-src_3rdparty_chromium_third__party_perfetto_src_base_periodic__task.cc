--- src/3rdparty/chromium/third_party/perfetto/src/base/periodic_task.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/base/periodic_task.cc
@@ -24,7 +24,7 @@
 #include "perfetto/base/time.h"
 #include "perfetto/ext/base/file_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
 #include <sys/timerfd.h>
 #endif
@@ -34,7 +34,7 @@ base::ScopedPlatformHandle CreateTimerFd(uint32_t peri
 
 namespace {
 base::ScopedPlatformHandle CreateTimerFd(uint32_t period_ms) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
   base::ScopedPlatformHandle tfd(
       timerfd_create(CLOCK_BOOTTIME, TFD_CLOEXEC | TFD_NONBLOCK));
