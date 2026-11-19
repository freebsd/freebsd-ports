--- components/enterprise/net/core/proxy_provisioning_domains_policy_handler.cc.orig	2026-11-19 12:25:27 UTC
+++ components/enterprise/net/core/proxy_provisioning_domains_policy_handler.cc
@@ -32,7 +32,7 @@ bool ProxyProvisioningDomainsPolicyHandler::CheckPolic
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!CheckUserAffiliatedProxyPolicy(policies, policy_name(), errors)) {
     return false;
   }
