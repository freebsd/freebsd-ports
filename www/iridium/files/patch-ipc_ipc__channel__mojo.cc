--- ipc/ipc_channel_mojo.cc.orig	2020-02-03 21:52:47 UTC
+++ ipc/ipc_channel_mojo.cc
@@ -74,10 +74,10 @@ class MojoChannelFactory : public ChannelFactory {
 };
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 #if defined(OS_NACL)
   return -1;
 #else
