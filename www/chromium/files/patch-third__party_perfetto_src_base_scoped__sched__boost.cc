--- third_party/perfetto/src/base/scoped_sched_boost.cc.orig	2025-09-06 10:01:20 UTC
+++ third_party/perfetto/src/base/scoped_sched_boost.cc
@@ -18,8 +18,9 @@
 
 #include "perfetto/ext/base/status_macros.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 #include <sched.h>         // for 'SCHED_' macros and 'sched_' functions
 #include <sys/resource.h>  // for 'setpriority', 'getpriority', 'PRIO_PROCESS'
 #include <sys/types.h>     // for 'pid_t'
@@ -31,8 +32,9 @@
 
 namespace perfetto::base {
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 
 namespace {
 constexpr pid_t kCurrentPid = 0;
