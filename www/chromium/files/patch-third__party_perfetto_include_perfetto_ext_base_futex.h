--- third_party/perfetto/include/perfetto/ext/base/futex.h.orig	2026-11-12 08:14:27 UTC
+++ third_party/perfetto/include/perfetto/ext/base/futex.h
@@ -26,7 +26,7 @@
 // TODO(rsavitski): Add support for other platforms.
 #define PERFETTO_HAS_FUTEX()                            \
   (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID))
+   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 namespace perfetto::base {
 
