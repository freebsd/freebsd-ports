--- extensions/browser/pref_names.cc.orig	2023-02-08 09:03:45 UTC
+++ extensions/browser/pref_names.cc
@@ -49,7 +49,7 @@ const char kStorageGarbageCollect[] = "extensions.stor
 const char kDeletedComponentExtensions[] =
     "extensions.deleted_component_extensions";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kChromeAppsEnabled[] = "extensions.chrome_apps_enabled";
 #endif
 
