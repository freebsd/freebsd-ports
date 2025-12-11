--- ipc/ipc_channel.cc.orig	2025-12-10 15:04:57 UTC
+++ ipc/ipc_channel.cc
@@ -41,7 +41,7 @@ namespace {
 // Global atomic used to guarantee channel IDs are unique.
 base::AtomicSequenceNumber g_last_id;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 int g_global_pid = 0;
 
@@ -83,7 +83,7 @@ class ThreadSafeChannelProxy : public mojo::ThreadSafe
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid()) {
     return global_pid;
   }
@@ -123,7 +123,7 @@ std::string Channel::GenerateUniqueRandomChannelID() {
       base::RandInt(0, std::numeric_limits<int32_t>::max()));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   g_global_pid = pid;
