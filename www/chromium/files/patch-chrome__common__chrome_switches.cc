--- ./chrome/common/chrome_switches.cc.orig	2014-04-24 22:34:45.000000000 +0200
+++ ./chrome/common/chrome_switches.cc	2014-04-24 23:23:43.000000000 +0200
@@ -1587,7 +1587,7 @@
 const char kPasswordStore[]                 = "password-store";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 // Triggers migration of user data directory to another directory
 // specified as a parameter. The migration is done under singleton lock,
 // and sanity checks are made to avoid corrupting the profile.
@@ -1598,7 +1598,7 @@
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
 const char kEnableSpeechDispatcher[] = "enable-speech-dispatcher";
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 
 #if defined(OS_MACOSX)
 // Disables the creation and launch of app shims for platform apps.
