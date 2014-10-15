--- chrome/common/chrome_switches.cc.orig	2014-10-02 19:39:46.000000000 +0200
+++ chrome/common/chrome_switches.cc	2014-10-15 11:59:52.000000000 +0200
@@ -1127,6 +1127,10 @@
 // "tls1.2").
 const char kSSLVersionMin[]                 = "ssl-version-min";
 
+// Specifies the minimum SSL/TLS version ("ssl3", "tls1", "tls1.1", or
+// "tls1.2") that TLS fallback will accept.
+const char kSSLVersionFallbackMin[]         = "ssl-version-fallback-min";
+
 // Starts the browser maximized, regardless of any previous settings.
 const char kStartMaximized[]                = "start-maximized";
 
@@ -1277,13 +1281,13 @@
 const char kPasswordStore[]                 = "password-store";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 // Triggers migration of user data directory to another directory
 // specified as a parameter. The migration is done under singleton lock,
 // and sanity checks are made to avoid corrupting the profile.
 // The browser exits after migration is complete.
 const char kMigrateDataDirForSxS[]          = "migrate-data-dir-for-sxs";
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 
 #if defined(OS_MACOSX)
 // Prevents Chrome from quitting when Chrome Apps are open.
