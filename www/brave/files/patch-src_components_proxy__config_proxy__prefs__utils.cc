--- src/components/proxy_config/proxy_prefs_utils.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/proxy_config/proxy_prefs_utils.cc
@@ -64,7 +64,7 @@ net::ProxyChain ProxyOverrideRuleProxyFr
 bool ProxyOverrideRulesAllowed(const PrefService* pref_service,
                                policy::PolicyService* policy_service) {
   CHECK(pref_service);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
       1) {
     return true;
