--- third_party/perfetto/src/base/watchdog_posix.cc.orig	2021-04-14 18:43:06 UTC
+++ third_party/perfetto/src/base/watchdog_posix.cc
@@ -114,8 +114,9 @@ void Watchdog::Start() {
   } else {
     PERFETTO_DCHECK(!enabled_);
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
     // Kick the thread to start running but only on Android or Linux.
     enabled_ = true;
     thread_ = std::thread(&Watchdog::ThreadMain, this);
