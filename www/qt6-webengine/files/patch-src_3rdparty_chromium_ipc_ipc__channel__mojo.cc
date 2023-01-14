--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -112,7 +112,7 @@ base::ProcessId GetSelfPID() {
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
