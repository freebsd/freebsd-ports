--- third_party/perfetto/src/base/file_utils.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/perfetto/src/base/file_utils.cc
@@ -61,8 +61,10 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 // For inotify. QNX doesn't have full support for inotify_init1().
 #include <sys/inotify.h>
 #endif
@@ -739,8 +741,10 @@ std::optional<uint64_t> GetFileSize(int fd) {
 
 // LinuxFileWatch
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 namespace {
 
