--- third_party/perfetto/src/tracing/ipc/default_socket.cc.orig	2021-09-14 01:58:28 UTC
+++ third_party/perfetto/src/tracing/ipc/default_socket.cc
@@ -26,7 +26,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <unistd.h>
 #endif
 
@@ -38,7 +39,7 @@ const char* kRunPerfettoBaseDir = "/run/perfetto/";
 // On Linux and CrOS, check /run/perfetto/ before using /tmp/ as the socket
 // base directory.
 bool UseRunPerfettoBaseDir() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   // Note that the trailing / in |kRunPerfettoBaseDir| ensures we are checking
   // against a directory, not a file.
   int res = PERFETTO_EINTR(access(kRunPerfettoBaseDir, X_OK));
