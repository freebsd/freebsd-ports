--- ipc/ipc_channel.h.orig	2021-09-14 01:51:58 UTC
+++ ipc/ipc_channel.h
@@ -236,7 +236,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
