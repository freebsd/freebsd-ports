--- remoting/host/chromoting_host.cc.orig	2025-09-11 13:19:19 UTC
+++ remoting/host/chromoting_host.cc
@@ -138,7 +138,7 @@ void ChromotingHost::Start(const std::string& host_own
       &ChromotingHost::OnIncomingSession, base::Unretained(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
