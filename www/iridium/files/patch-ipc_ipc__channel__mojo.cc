--- ipc/ipc_channel_mojo.cc.orig	2023-01-17 19:19:00 UTC
+++ ipc/ipc_channel_mojo.cc
@@ -113,7 +113,7 @@ class ThreadSafeChannelProxy : public mojo::ThreadSafe
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
