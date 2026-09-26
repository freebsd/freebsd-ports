--- remoting/host/ipc_desktop_environment.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -180,7 +180,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
                               ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
@@ -192,7 +192,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
   void OnTerminalDisconnected(ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
       override;
@@ -351,7 +351,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
                          error_details, error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   OnSessionServicesClientConnected(GetEventsReceivers().current_context(),
@@ -397,7 +397,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
@@ -511,7 +511,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
                                 error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnectedForTesting(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
