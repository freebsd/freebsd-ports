--- remoting/host/ipc_desktop_environment.cc.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -378,7 +378,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
