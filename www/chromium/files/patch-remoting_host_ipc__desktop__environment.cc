--- remoting/host/ipc_desktop_environment.cc.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -187,7 +187,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
                               ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
@@ -199,7 +199,7 @@ class IpcDesktopEnvironmentFactory::Core : public mojo
   void OnTerminalDisconnected(ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
       override;
@@ -358,7 +358,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
                          error_details, error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   OnSessionServicesClientConnected(GetEventsReceivers().current_context(),
@@ -404,7 +404,7 @@ void IpcDesktopEnvironmentFactory::Core::OnTerminalDis
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
@@ -518,7 +518,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
                                 error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnectedForTesting(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
