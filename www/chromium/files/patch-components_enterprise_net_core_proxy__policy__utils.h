--- components/enterprise/net/core/proxy_policy_utils.h.orig	2026-11-19 12:25:27 UTC
+++ components/enterprise/net/core/proxy_policy_utils.h
@@ -17,7 +17,7 @@ class PolicyMap;
 namespace enterprise_net {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Returns true if the machine-scoped EnableProxyOverrideRulesForAllUsers policy
 // is enabled (set to 1).
 bool IsUnaffiliatedUserProxyPolicyAllowed(const policy::PolicyMap& policies);
