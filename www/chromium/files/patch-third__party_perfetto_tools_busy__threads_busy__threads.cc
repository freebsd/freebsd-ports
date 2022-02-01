--- third_party/perfetto/tools/busy_threads/busy_threads.cc.orig	2021-12-31 01:00:55 UTC
+++ third_party/perfetto/tools/busy_threads/busy_threads.cc
@@ -30,7 +30,8 @@
 #define PERFETTO_HAVE_PTHREADS                \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE))
+   PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+   PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD))
 
 #if PERFETTO_HAVE_PTHREADS
 #include <pthread.h>
