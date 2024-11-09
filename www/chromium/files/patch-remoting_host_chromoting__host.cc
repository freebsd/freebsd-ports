--- remoting/host/chromoting_host.cc.orig	2024-10-22 08:31:56 UTC
+++ remoting/host/chromoting_host.cc
@@ -132,7 +132,7 @@ void ChromotingHost::Start(const std::string& host_own
       &ChromotingHost::OnIncomingSession, base::Unretained(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
