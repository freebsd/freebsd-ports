--- ipc/ipc_channel_mojo.cc.orig	2017-08-10 04:18:45.930792000 +0200
+++ ipc/ipc_channel_mojo.cc	2017-08-10 04:19:05.792138000 +0200
@@ -228,7 +228,7 @@
 }
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // OS_LINUX
