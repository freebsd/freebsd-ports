--- components/enterprise/connectors/core/connectors_prefs.cc.orig	2025-11-06 10:11:34 UTC
+++ components/enterprise/connectors/core/connectors_prefs.cc
@@ -22,7 +22,7 @@
 namespace enterprise_connectors {
 
 // Profile Prefs
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kCacheEncryptionEnabledPref[] =
     "enterprise_connectors.cache_encryption_enabled";
 #endif
@@ -96,7 +96,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
 #if BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
   client_certificates::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(kCacheEncryptionEnabledPref, false);
 #endif
 }
