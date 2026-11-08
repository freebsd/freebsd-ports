--- ipc/ipc_channel.cc.orig	2026-09-25 15:26:43 UTC
+++ ipc/ipc_channel.cc
@@ -34,7 +34,7 @@ namespace IPC {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 int g_global_pid = 0;
 
@@ -76,7 +76,7 @@ class ThreadSafeChannelProxy : public mojo::ThreadSafe
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid()) {
     return global_pid;
   }
@@ -97,7 +97,7 @@ std::unique_ptr<Channel> Channel::Create(
                                       ipc_task_runner, proxy_task_runner));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   g_global_pid = pid;
