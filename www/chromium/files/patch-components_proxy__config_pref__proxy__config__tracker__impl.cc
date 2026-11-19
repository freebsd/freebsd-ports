--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-11-19 12:25:27 UTC
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -588,7 +588,7 @@ void PrefProxyConfigTrackerImpl::RegisterPrefs(PrefReg
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
@@ -605,7 +605,7 @@ void PrefProxyConfigTrackerImpl::RegisterProfilePrefs(
   registry->RegisterBooleanPref(proxy_config::prefs::kUseSharedProxies, false);
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
