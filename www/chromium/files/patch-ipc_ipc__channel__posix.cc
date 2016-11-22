--- ipc/ipc_channel_posix.cc.orig	2016-07-20 22:03:25.000000000 +0300
+++ ipc/ipc_channel_posix.cc	2016-08-13 00:06:40.205716000 +0300
@@ -183,9 +183,9 @@

 //------------------------------------------------------------------------------

-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int ChannelPosix::global_pid_ = 0;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)

 ChannelPosix::ChannelPosix(const IPC::ChannelHandle& channel_handle,
                            Mode mode,
@@ -613,7 +613,7 @@
   return base::PathExists(base::FilePath(channel_id));
 }

-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void ChannelPosix::SetGlobalPid(int pid) {
   global_pid_ = pid;
@@ -622,7 +622,7 @@
 int ChannelPosix::GetGlobalPid() {
   return global_pid_;
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)

 // Called by libevent when we can read from the pipe without blocking.
 void ChannelPosix::OnFileCanReadWithoutBlocking(int fd) {
@@ -813,12 +813,12 @@
   return -1;
 #else
   int pid = base::GetCurrentProcId();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Our process may be in a sandbox with a separate PID namespace.
   if (global_pid_) {
     pid = global_pid_;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return pid;
 #endif  // defined(OS_NACL_NONSFI)
 }
@@ -1135,7 +1135,7 @@
   return ChannelPosix::IsNamedServerInitialized(channel_id);
 }

-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   ChannelPosix::SetGlobalPid(pid);
@@ -1143,6 +1143,6 @@
 int Channel::GetGlobalPid() {
   return ChannelPosix::GetGlobalPid();
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)

 }  // namespace IPC
