--- remoting/host/ipc_desktop_environment.h.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/ipc_desktop_environment.h
@@ -174,7 +174,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
