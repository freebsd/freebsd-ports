--- ./chrome/common/pref_names.cc.orig	2014-08-12 21:02:17.000000000 +0200
+++ ./chrome/common/pref_names.cc	2014-08-13 09:56:57.000000000 +0200
@@ -923,7 +923,7 @@
 // Boolean controlling whether SafeSearch is mandatory for Google Web Searches.
 const char kForceSafeSearch[] = "settings.force_safesearch";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
