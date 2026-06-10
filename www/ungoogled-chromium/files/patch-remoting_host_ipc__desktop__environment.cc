--- remoting/host/ipc_desktop_environment.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -367,7 +367,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
