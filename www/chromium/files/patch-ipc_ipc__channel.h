--- ipc/ipc_channel.h.orig	2017-06-05 19:03:08 UTC
+++ ipc/ipc_channel.h
@@ -246,7 +246,7 @@ class IPC_EXPORT Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
