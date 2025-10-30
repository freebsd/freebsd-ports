--- ipc/ipc_channel.h.orig	2025-10-30 15:44:36 UTC
+++ ipc/ipc_channel.h
@@ -206,7 +206,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
