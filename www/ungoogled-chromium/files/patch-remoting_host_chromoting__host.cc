--- remoting/host/chromoting_host.cc.orig	2026-02-15 10:01:45 UTC
+++ remoting/host/chromoting_host.cc
@@ -144,7 +144,7 @@ void ChromotingHost::Start(const std::string& host_own
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
