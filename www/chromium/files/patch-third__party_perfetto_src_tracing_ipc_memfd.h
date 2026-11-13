--- third_party/perfetto/src/tracing/ipc/memfd.h.orig	2026-11-11 14:44:17 UTC
+++ third_party/perfetto/src/tracing/ipc/memfd.h
@@ -24,7 +24,8 @@
 // The build has the memfd code. HasMemfdSupport() also checks the kernel.
 #define PERFETTO_MEMFD_ENABLED()              \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX))
+  (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+  !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)))
 
 // Some android build bots use a sysroot that doesn't support memfd when
 // compiling for the host, so we define the flags we need ourselves.
