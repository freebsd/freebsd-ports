--- components/proxy_config/proxy_override_rules_policy_handler.h.orig	2026-02-15 10:01:45 UTC
+++ components/proxy_config/proxy_override_rules_policy_handler.h
@@ -53,7 +53,7 @@ class PROXY_CONFIG_EXPORT ProxyOverrideRulesPolicyHand
                 policy::PolicyErrorPath error_path,
                 policy::PolicyErrorMap* errors);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::IntRangePolicyHandler enabled_for_all_users_handler_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 };
