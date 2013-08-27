--- chrome/common/pref_names.cc.orig	2013-08-17 21:26:00.000000000 +0300
+++ chrome/common/pref_names.cc	2013-08-17 21:26:43.000000000 +0300
@@ -955,7 +955,7 @@
 // Boolean controlling whether SafeSearch is mandatory for Google Web Searches.
 const char kForceSafeSearch[] = "settings.force_safesearch";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
