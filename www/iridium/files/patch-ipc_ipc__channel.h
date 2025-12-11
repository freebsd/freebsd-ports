--- ipc/ipc_channel.h.orig	2025-12-10 15:04:57 UTC
+++ ipc/ipc_channel.h
@@ -201,7 +201,7 @@ class COMPONENT_EXPORT(IPC) Channel final
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
