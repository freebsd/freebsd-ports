--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -105,7 +105,7 @@ class ThreadSafeChannelProxy : public mojo::ThreadSafe
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
