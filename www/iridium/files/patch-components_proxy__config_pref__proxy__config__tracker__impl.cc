--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-01-16 14:21:21 UTC
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -552,7 +552,7 @@ void PrefProxyConfigTrackerImpl::RegisterPrefs(PrefReg
   registry->RegisterDictionaryPref(proxy_config::prefs::kProxy,
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
