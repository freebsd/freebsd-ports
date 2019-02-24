--- chrome/browser/prefs/pref_service_incognito_whitelist.cc.orig	2019-01-13 01:45:22.403758000 +0100
+++ chrome/browser/prefs/pref_service_incognito_whitelist.cc	2019-01-13 01:45:47.793792000 +0100
@@ -161,7 +161,7 @@
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
