--- components/enterprise/connectors/core/connectors_prefs.h.orig	2025-11-01 06:40:37 UTC
+++ components/enterprise/connectors/core/connectors_prefs.h
@@ -11,7 +11,7 @@ class PrefRegistrySimple;
 
 namespace enterprise_connectors {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Pref that maps to the "CacheEncryptionEnabled" policy.
 extern const char kCacheEncryptionEnabledPref[];
 #endif
