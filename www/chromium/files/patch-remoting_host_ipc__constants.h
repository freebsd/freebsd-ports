--- remoting/host/ipc_constants.h.orig	2026-03-13 06:02:14 UTC
+++ remoting/host/ipc_constants.h
@@ -38,7 +38,7 @@ extern const char kAgentProcessBrokerMessagePipeId[];
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
