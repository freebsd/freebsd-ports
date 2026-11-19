--- remoting/host/chromoting_host_services_client.cc.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/chromoting_host_services_client.cc
@@ -148,7 +148,7 @@ ChromotingHostServicesClient::ParseAgentStatusArgs(
 
 ChromotingHostServicesClient::ChromotingHostServicesClient()
     : ChromotingHostServicesClient(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           std::vector{GetChromotingHostServicesServerName(),
                       GetLegacyChromotingHostServicesServerName()}
 #else
@@ -217,7 +217,7 @@ bool ChromotingHostServicesClient::EnsureSessionServic
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
