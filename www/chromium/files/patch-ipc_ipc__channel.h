--- ipc/ipc_channel.h.orig	2016-08-13 00:25:04.291611000 +0300
+++ ipc/ipc_channel.h	2016-08-13 00:09:06.758895000 +0300
@@ -223,7 +223,7 @@
   static std::string GenerateVerifiedChannelID(const std::string& prefix);
 #endif

-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
