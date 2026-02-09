--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-02-16 10:45:29 UTC
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -527,7 +527,7 @@ void PrefProxyConfigTrackerImpl::RegisterPrefs(PrefReg
   registry->RegisterDictionaryPref(proxy_config::prefs::kProxy,
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
@@ -544,7 +544,7 @@ void PrefProxyConfigTrackerImpl::RegisterProfilePrefs(
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterBooleanPref(proxy_config::prefs::kUseSharedProxies, false);
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
