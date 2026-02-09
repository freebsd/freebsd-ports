--- components/proxy_config/proxy_override_rules_policy_handler.cc.orig	2026-02-16 10:45:29 UTC
+++ components/proxy_config/proxy_override_rules_policy_handler.cc
@@ -28,7 +28,7 @@ policy::PolicyErrorPath CreateNewPath(
   return path;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool UnaffiliatedPolicyAllowed(const policy::PolicyMap& policies) {
   const base::Value* enable_for_all_users_value =
       policies.GetValue(policy::key::kEnableProxyOverrideRulesForAllUsers,
@@ -49,7 +49,7 @@ ProxyOverrideRulesPolicyHandler::ProxyOverrideRulesPol
           policy::key::kProxyOverrideRules,
           schema.GetKnownProperty(policy::key::kProxyOverrideRules),
           policy::SchemaOnErrorStrategy::SCHEMA_ALLOW_UNKNOWN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       ,
       enabled_for_all_users_handler_(
           policy::key::kEnableProxyOverrideRulesForAllUsers,
@@ -66,7 +66,7 @@ ProxyOverrideRulesPolicyHandler::~ProxyOverrideRulesPo
 bool ProxyOverrideRulesPolicyHandler::CheckPolicySettings(
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // This code should run to set errors for
   // `kEnableProxyOverrideRulesForAllUsers`, but the regular proxy override
   // rules policy might still be valid so we ignore the returned boolean.
@@ -78,7 +78,7 @@ bool ProxyOverrideRulesPolicyHandler::CheckPolicySetti
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const policy::PolicyMap::Entry* proxy_override_rules_policy =
       policies.Get(policy_name());
   if (proxy_override_rules_policy &&
@@ -126,7 +126,7 @@ void ProxyOverrideRulesPolicyHandler::ApplyPolicySetti
 
   prefs->SetValue(proxy_config::prefs::kProxyOverrideRules,
                   policy_value->Clone());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   prefs->SetInteger(proxy_config::prefs::kProxyOverrideRulesScope,
                     policy->scope);
   prefs->SetBoolean(proxy_config::prefs::kProxyOverrideRulesAffiliation,
