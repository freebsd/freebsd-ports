--- third_party/perfetto/src/tracing/platform_posix.cc.orig	2025-12-10 15:04:57 UTC
+++ third_party/perfetto/src/tracing/platform_posix.cc
@@ -110,12 +110,13 @@ std::unique_ptr<base::TaskRunner> PlatformPosix::Creat
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
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   return std::string(getprogname());
 #else
   return "unknown_producer";
