--- remoting/host/ipc_desktop_environment.h.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/ipc_desktop_environment.h
@@ -175,7 +175,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
