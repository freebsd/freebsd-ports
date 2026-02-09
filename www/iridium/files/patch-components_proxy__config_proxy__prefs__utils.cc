--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-02-16 10:45:29 UTC
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -60,7 +60,7 @@ net::ProxyChain ProxyOverrideRuleProxyFromString(std::
 
 bool ProxyOverrideRulesAllowed(const PrefService* pref_service) {
   CHECK(pref_service);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kProxyOverrideRulesScope) ==
           policy::POLICY_SCOPE_USER &&
       !pref_service->GetBoolean(prefs::kProxyOverrideRulesAffiliation)) {
