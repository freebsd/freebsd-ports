--- ipc/ipc_channel.h.orig	2026-09-25 15:26:43 UTC
+++ ipc/ipc_channel.h
@@ -165,7 +165,7 @@ class COMPONENT_EXPORT(IPC) Channel final
   void OnAssociatedInterfaceRequest(
       mojo::GenericPendingAssociatedReceiver receiver) override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
