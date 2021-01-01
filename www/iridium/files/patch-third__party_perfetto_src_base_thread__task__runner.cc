--- third_party/perfetto/src/base/thread_task_runner.cc.orig	2020-03-19 11:48:14 UTC
+++ third_party/perfetto/src/base/thread_task_runner.cc
@@ -27,7 +27,7 @@
 #include "perfetto/base/logging.h"
 #include "perfetto/ext/base/unix_task_runner.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -84,6 +84,8 @@ void ThreadTaskRunner::RunTaskThread(
   if (!name_.empty()) {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX)
     pthread_setname_np(name_.c_str());
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+    pthread_set_name_np(pthread_self(), name_.c_str());
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
     prctl(PR_SET_NAME, name_.c_str());
