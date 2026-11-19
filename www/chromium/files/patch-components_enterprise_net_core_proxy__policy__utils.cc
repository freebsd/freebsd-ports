--- components/enterprise/net/core/proxy_policy_utils.cc.orig	2026-11-19 12:25:27 UTC
+++ components/enterprise/net/core/proxy_policy_utils.cc
@@ -17,7 +17,7 @@
 namespace enterprise_net {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool IsUnaffiliatedUserProxyPolicyAllowed(const policy::PolicyMap& policies) {
   const policy::PolicyMap::Entry* entry =
       policies.Get(policy::key::kEnableProxyOverrideRulesForAllUsers);
