--- src/remoting/host/chromoting_host.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/chromoting_host.cc
@@ -143,7 +143,7 @@ void ChromotingHost::Start(const std::st
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
@@ -162,7 +162,7 @@ void ChromotingHost::BindChromotingHostS
 }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindChromotingHostServices(
     mojo::PendingReceiver<mojom::ChromotingHostServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -297,7 +297,7 @@ std::optional<ErrorCode> ChromotingHost:
   return per_session_policies_validator_.Run(policies);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::BindSessionServices(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
