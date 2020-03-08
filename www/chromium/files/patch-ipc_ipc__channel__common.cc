--- ipc/ipc_channel_common.cc.orig	2020-03-03 18:53:09 UTC
+++ ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
@@ -26,7 +26,7 @@ int Channel::GetGlobalPid() {
   return g_global_pid;
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 std::unique_ptr<Channel> Channel::CreateClient(
