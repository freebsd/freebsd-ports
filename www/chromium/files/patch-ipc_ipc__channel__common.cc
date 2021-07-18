--- ipc/ipc_channel_common.cc.orig	2021-04-14 18:41:05 UTC
+++ ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
@@ -26,7 +26,7 @@ int Channel::GetGlobalPid() {
   return g_global_pid;
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // static
 std::unique_ptr<Channel> Channel::CreateClient(
