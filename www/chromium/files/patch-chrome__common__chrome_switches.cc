--- chrome/common/chrome_switches.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/common/chrome_switches.cc
@@ -1275,13 +1275,13 @@
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
