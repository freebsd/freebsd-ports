--- remoting/host/chromoting_host.cc.orig	2023-01-11 09:17:16 UTC
+++ remoting/host/chromoting_host.cc
@@ -125,7 +125,7 @@ void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ipc_server_ = std::make_unique<
       named_mojo_ipc_server::NamedMojoIpcServer<mojom::ChromotingHostServices>>(
       GetChromotingHostServicesServerName(), this,
