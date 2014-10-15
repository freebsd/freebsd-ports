--- chrome/common/pref_names.h.orig	2014-10-02 19:39:46.000000000 +0200
+++ chrome/common/pref_names.h	2014-10-15 11:59:52.000000000 +0200
@@ -291,7 +291,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -405,6 +405,7 @@
 extern const char kCertRevocationCheckingRequiredLocalAnchors[];
 extern const char kSSLVersionMin[];
 extern const char kSSLVersionMax[];
+extern const char kSSLVersionFallbackMin[];
 extern const char kCipherSuiteBlacklist[];
 extern const char kDisableSSLRecordSplitting[];
 
