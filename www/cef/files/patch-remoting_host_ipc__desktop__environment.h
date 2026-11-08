--- remoting/host/ipc_desktop_environment.h.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/ipc_desktop_environment.h
@@ -135,7 +135,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
                               ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
@@ -177,7 +177,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
   // the same email address reconnects, the desktop session will be reused and
   // the desktop process will be requested to send a new desktop pipe.
   // TODO: yuweih - see if it makes sense to enable it on Windows.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool persist_desktop_sessions_ = true;
 #else
   bool persist_desktop_sessions_ = false;
