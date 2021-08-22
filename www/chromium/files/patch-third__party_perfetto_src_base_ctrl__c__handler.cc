--- third_party/perfetto/src/base/ctrl_c_handler.cc.orig	2021-07-19 18:47:28 UTC
+++ third_party/perfetto/src/base/ctrl_c_handler.cc
@@ -50,7 +50,8 @@ void InstallCtrCHandler(CtrlCHandlerFunction handler) 
   ::SetConsoleCtrlHandler(trampoline, true);
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)   || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   // Setup signal handler.
   struct sigaction sa {};
 
