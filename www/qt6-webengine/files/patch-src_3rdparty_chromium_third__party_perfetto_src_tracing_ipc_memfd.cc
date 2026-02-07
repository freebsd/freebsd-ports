--- src/3rdparty/chromium/third_party/perfetto/src/tracing/ipc/memfd.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/ipc/memfd.cc
@@ -20,7 +20,8 @@
 
 #define PERFETTO_MEMFD_ENABLED()             \
   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-  PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX)
+  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+  !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD))
 
 #if PERFETTO_MEMFD_ENABLED()
 
