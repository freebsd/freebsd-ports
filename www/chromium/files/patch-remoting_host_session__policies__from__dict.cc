--- remoting/host/session_policies_from_dict.cc.orig	2026-08-12 09:02:10 UTC
+++ remoting/host/session_policies_from_dict.cc
@@ -77,7 +77,7 @@ std::optional<SessionPolicies> SessionPoliciesFromDict
   session_policies.curtain_required =
       dict.FindBool(policy::key::kRemoteAccessHostRequireCurtain);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   session_policies.host_username_match_required =
       dict.FindBool(policy::key::kRemoteAccessHostMatchUsername);
 #endif
