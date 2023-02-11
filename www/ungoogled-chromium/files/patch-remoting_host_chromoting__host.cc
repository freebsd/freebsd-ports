--- remoting/host/chromoting_host.cc.orig	2023-02-11 09:11:04 UTC
+++ remoting/host/chromoting_host.cc
@@ -130,7 +130,7 @@ void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   named_mojo_ipc_server::EndpointOptions options;
   options.server_name = GetChromotingHostServicesServerName();
 #if BUILDFLAG(IS_WIN)
