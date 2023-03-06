--- src/3rdparty/chromium/third_party/perfetto/src/base/thread_task_runner.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/base/thread_task_runner.cc
@@ -28,7 +28,7 @@
 #include "perfetto/ext/base/thread_utils.h"
 #include "perfetto/ext/base/unix_task_runner.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
