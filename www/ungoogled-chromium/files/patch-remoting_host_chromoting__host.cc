--- remoting/host/chromoting_host.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/host/chromoting_host.cc
@@ -142,7 +142,7 @@ void ChromotingHost::Start(const std::string& host_own
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
@@ -161,7 +161,7 @@ void ChromotingHost::BindChromotingHostServicesForServ
 }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindChromotingHostServices(
     mojo::PendingReceiver<mojom::ChromotingHostServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -300,7 +300,7 @@ std::optional<ErrorCode> ChromotingHost::OnSessionPoli
   return per_session_policies_validator_.Run(policies);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindSessionServices(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
