--- ./chrome/common/pref_names.cc.orig	2014-04-24 22:34:45.000000000 +0200
+++ ./chrome/common/pref_names.cc	2014-04-24 23:23:43.000000000 +0200
@@ -963,7 +963,7 @@
 // Boolean controlling whether SafeSearch is mandatory for Google Web Searches.
 const char kForceSafeSearch[] = "settings.force_safesearch";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
