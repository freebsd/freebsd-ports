--- remoting/host/ipc_desktop_environment.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -181,7 +181,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
                               ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
@@ -193,7 +193,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
   void OnTerminalDisconnected(ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
       override;
@@ -352,7 +352,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
                          error_details, error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   OnSessionServicesClientConnected(GetEventsReceivers().current_context(),
@@ -398,7 +398,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
@@ -512,7 +512,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
                                 error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnectedForTesting(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
