--- extensions/browser/pref_names.cc.orig	2021-12-16 15:11:20 UTC
+++ extensions/browser/pref_names.cc
@@ -47,7 +47,7 @@ const char kStorageGarbageCollect[] = "extensions.stor
 const char kToolbar[] = "extensions.toolbar";
 const char kDeletedComponentExtensions[] =
     "extensions.deleted_component_extensions";
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kChromeAppsEnabled[] = "extensions.chrome_apps_enabled";
 #endif
 const char kU2fSecurityKeyApiEnabled[] =
