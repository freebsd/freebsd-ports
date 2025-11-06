--- ipc/ipc_channel.cc.orig	2025-11-06 10:11:34 UTC
+++ ipc/ipc_channel.cc
@@ -22,7 +22,7 @@ namespace {
 // Global atomic used to guarantee channel IDs are unique.
 base::AtomicSequenceNumber g_last_id;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 int g_global_pid = 0;
 
@@ -60,7 +60,7 @@ std::string Channel::GenerateUniqueRandomChannelID() {
       base::RandInt(0, std::numeric_limits<int32_t>::max()));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   g_global_pid = pid;
