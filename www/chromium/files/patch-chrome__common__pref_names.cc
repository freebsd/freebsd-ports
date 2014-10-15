--- chrome/common/pref_names.cc.orig	2014-10-02 19:39:46.000000000 +0200
+++ chrome/common/pref_names.cc	2014-10-15 11:59:52.000000000 +0200
@@ -898,7 +898,7 @@
 // Boolean controlling whether SafeSearch is mandatory for Google Web Searches.
 const char kForceSafeSearch[] = "settings.force_safesearch";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1288,6 +1288,7 @@
     "ssl.rev_checking.required_for_local_anchors";
 const char kSSLVersionMin[] = "ssl.version_min";
 const char kSSLVersionMax[] = "ssl.version_max";
+const char kSSLVersionFallbackMin[] = "ssl.version_fallback_min";
 const char kCipherSuiteBlacklist[] = "ssl.cipher_suites.blacklist";
 const char kDisableSSLRecordSplitting[] = "ssl.ssl_record_splitting.disabled";
 
