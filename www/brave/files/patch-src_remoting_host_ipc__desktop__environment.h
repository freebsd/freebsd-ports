--- src/remoting/host/ipc_desktop_environment.h.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/ipc_desktop_environment.h
@@ -173,7 +173,7 @@ class IpcDesktopEnvironmentFactory : pub
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
