--- chrome/common/chrome_switches.cc.orig	2013-11-08 07:41:00.000000000 +0100
+++ chrome/common/chrome_switches.cc	2013-11-16 01:18:01.000000000 +0100
@@ -1563,13 +1563,13 @@
 #endif
 #endif  // OS_POSIX
 
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
 // Forcibly disables Lion-style on newer OSes, to allow developers to test the
