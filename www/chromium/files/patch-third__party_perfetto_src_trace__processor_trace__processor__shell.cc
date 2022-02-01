--- third_party/perfetto/src/trace_processor/trace_processor_shell.cc.orig	2021-12-14 11:47:12 UTC
+++ third_party/perfetto/src/trace_processor/trace_processor_shell.cc
@@ -60,7 +60,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_HAS_SIGNAL_H() 1
 #else
 #define PERFETTO_HAS_SIGNAL_H() 0
@@ -108,7 +109,8 @@ std::string GetConfigPath() {
   const char* homedir = getenv("HOME");
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   if (homedir == nullptr)
     homedir = getpwuid(getuid())->pw_dir;
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
