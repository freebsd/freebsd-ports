--- third_party/perfetto/src/base/thread_task_runner.cc.orig	2020-07-07 22:03:25 UTC
+++ third_party/perfetto/src/base/thread_task_runner.cc
@@ -28,7 +28,7 @@
 #include "perfetto/ext/base/thread_utils.h"
 #include "perfetto/ext/base/unix_task_runner.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
