--- components/proxy_config/proxy_override_rules_policy_handler.cc.orig	2026-11-19 12:25:27 UTC
+++ components/proxy_config/proxy_override_rules_policy_handler.cc
@@ -45,7 +45,7 @@ bool ProxyOverrideRulesPolicyHandler::CheckPolicySetti
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!enterprise_net::CheckUserAffiliatedProxyPolicy(policies, policy_name(),
                                                       errors)) {
     return false;
@@ -97,7 +97,7 @@ void ProxyOverrideRulesPolicyHandler::ApplyPolicySetti
                   policy_value->Clone());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   prefs->SetInteger(proxy_config::prefs::kProxyOverrideRulesScope,
                     policy->scope);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
