--- remoting/host/mojo_ipc_server.cc.orig	2021-07-28 08:18:06 UTC
+++ remoting/host/mojo_ipc_server.cc
@@ -12,9 +12,9 @@
 #include "build/build_config.h"
 #include "mojo/public/cpp/system/invitation.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/file_util.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "base/strings/stringprintf.h"
@@ -101,7 +101,7 @@ void MojoIpcServerBase::StopServer() {
   server_started_ = false;
   CloseAllConnections();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Any pending invitations will become orphaned, and a client that accepts an
   // orphaned invitation may incorrectly believe that the server is still alive,
   // so we just simply delete the socket file to prevent clients from
@@ -109,7 +109,7 @@ void MojoIpcServerBase::StopServer() {
   io_sequence_->PostTask(FROM_HERE,
                          base::BindOnce(base::IgnoreResult(&base::DeleteFile),
                                         base::FilePath(server_name_)));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 void MojoIpcServerBase::SendInvitation() {
