--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-03-13 06:02:14 UTC
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -60,7 +60,7 @@ net::ProxyChain ProxyOverrideRuleProxyFromString(std::
 
 bool ProxyOverrideRulesAllowed(const PrefService* pref_service) {
   CHECK(pref_service);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (pref_service->GetBoolean(prefs::kProxyOverrideRulesAffiliation) ||
       pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
           1) {
