--- third_party/perfetto/src/base/watchdog_posix.cc.orig	2021-12-31 01:00:54 UTC
+++ third_party/perfetto/src/base/watchdog_posix.cc
@@ -170,8 +170,9 @@ void Watchdog::Start() {
   } else {
     PERFETTO_DCHECK(!enabled_);
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
     // Kick the thread to start running but only on Android or Linux.
     timer_fd_.reset(
         timerfd_create(CLOCK_MONOTONIC, TFD_CLOEXEC | TFD_NONBLOCK));
