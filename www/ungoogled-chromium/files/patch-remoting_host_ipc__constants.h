--- remoting/host/ipc_constants.h.orig	2026-05-09 18:09:27 UTC
+++ remoting/host/ipc_constants.h
@@ -31,7 +31,7 @@ bool GetInstalledBinaryPath(const base::FilePath::Stri
 const mojo::NamedPlatformChannel::ServerName&
 GetChromotingHostServicesServerName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the server name for the legacy single-process Linux host.
 const mojo::NamedPlatformChannel::ServerName&
 GetLegacyChromotingHostServicesServerName();
@@ -45,7 +45,7 @@ extern const char kAgentProcessBrokerMessagePipeId[];
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
