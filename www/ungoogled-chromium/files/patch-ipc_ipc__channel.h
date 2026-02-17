--- ipc/ipc_channel.h.orig	2026-02-15 10:01:45 UTC
+++ ipc/ipc_channel.h
@@ -168,7 +168,7 @@ class COMPONENT_EXPORT(IPC) Channel final
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
