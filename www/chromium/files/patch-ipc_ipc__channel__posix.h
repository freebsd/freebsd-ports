--- ipc/ipc_channel_posix.h.orig	2016-08-13 00:22:20.959322000 +0300
+++ ipc/ipc_channel_posix.h	2016-08-13 00:07:29.393338000 +0300
@@ -63,10 +63,10 @@
   void CloseClientFileDescriptor();

   static bool IsNamedServerInitialized(const std::string& channel_id);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static void SetGlobalPid(int pid);
   static int GetGlobalPid();
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)

  private:
   bool CreatePipe(const IPC::ChannelHandle& channel_handle);
@@ -209,10 +209,10 @@
   // True if we are responsible for unlinking the unix domain socket file.
   bool must_unlink_;

-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If non-zero, overrides the process ID sent in the hello message.
   static int global_pid_;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)

   DISALLOW_IMPLICIT_CONSTRUCTORS(ChannelPosix);
 };
