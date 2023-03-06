--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -74,10 +74,10 @@ base::ProcessId GetSelfPID() {
 };
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_NACL)
   return -1;
 #else
