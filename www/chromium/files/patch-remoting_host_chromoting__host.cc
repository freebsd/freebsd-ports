--- remoting/host/chromoting_host.cc.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/chromoting_host.cc
@@ -137,7 +137,7 @@ void ChromotingHost::Start(const std::string& host_own
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
@@ -156,7 +156,7 @@ void ChromotingHost::BindChromotingHostServicesForServ
 }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindChromotingHostServices(
     mojo::PendingReceiver<mojom::ChromotingHostServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -295,7 +295,7 @@ std::optional<ErrorCode> ChromotingHost::OnSessionPoli
   return per_session_policies_validator_.Run(policies);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindSessionServices(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
