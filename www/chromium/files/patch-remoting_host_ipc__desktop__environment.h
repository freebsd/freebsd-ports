--- remoting/host/ipc_desktop_environment.h.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/ipc_desktop_environment.h
@@ -130,7 +130,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
       int terminal_id,
       mojo::ScopedMessagePipeHandle desktop_pipe) override;
   void OnTerminalDisconnected(int terminal_id) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
@@ -172,7 +172,7 @@ class IpcDesktopEnvironmentFactory : public DesktopEnv
   // the same email address reconnects, the desktop session will be reused and
   // the desktop process will be requested to send a new desktop pipe.
   // TODO: yuweih - see if it makes sense to enable it on Windows.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool persist_desktop_sessions_ = true;
 #else
   bool persist_desktop_sessions_ = false;
