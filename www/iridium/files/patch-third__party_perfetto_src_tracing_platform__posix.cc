--- third_party/perfetto/src/tracing/platform_posix.cc.orig	2026-01-16 14:21:21 UTC
+++ third_party/perfetto/src/tracing/platform_posix.cc
@@ -111,13 +111,15 @@ std::unique_ptr<base::TaskRunner> PlatformPosix::Creat
 }
 
 std::string PlatformPosix::GetCurrentProcessName() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string cmdline;
   base::ReadFile("/proc/self/cmdline", &cmdline);
   return cmdline.substr(0, cmdline.find('\0'));
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
   return std::string(getprogname());
 #else
   return "unknown_producer";
