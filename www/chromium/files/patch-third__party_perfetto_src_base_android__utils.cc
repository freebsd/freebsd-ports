--- third_party/perfetto/src/base/android_utils.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/perfetto/src/base/android_utils.cc
@@ -38,8 +38,10 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <sys/sysinfo.h>
 #endif
 
@@ -105,8 +107,10 @@ SystemInfo GetSystemInfo() {
   info.page_size = static_cast<uint32_t>(sysconf(_SC_PAGESIZE));
   info.num_cpus = static_cast<uint32_t>(sysconf(_SC_NPROCESSORS_CONF));
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   // Use the Linux-specific sysinfo() system call on Linux and Android.
   // https://man7.org/linux/man-pages/man2/sysinfo.2.html
   struct sysinfo sys_info;
