--- ./chrome/common/pref_names.cc.orig	2014-04-30 22:42:23.000000000 +0200
+++ ./chrome/common/pref_names.cc	2014-05-04 14:38:46.000000000 +0200
@@ -950,7 +950,7 @@
 // Boolean controlling whether SafeSearch is mandatory for Google Web Searches.
 const char kForceSafeSearch[] = "settings.force_safesearch";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
