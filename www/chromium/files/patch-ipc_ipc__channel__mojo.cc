--- ipc/ipc_channel_mojo.cc.orig	2019-12-16 21:51:27 UTC
+++ ipc/ipc_channel_mojo.cc
@@ -65,10 +65,10 @@ class MojoChannelFactory : public ChannelFactory {
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
