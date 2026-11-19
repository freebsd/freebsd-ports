--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-11-19 12:25:27 UTC
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -65,7 +65,7 @@ bool ProxyOverrideRulesAllowed(const PrefService* pref
                                policy::PolicyService* policy_service) {
   CHECK(pref_service);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
       1) {
     return true;
