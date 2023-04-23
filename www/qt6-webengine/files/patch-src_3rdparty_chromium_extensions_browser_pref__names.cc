--- src/3rdparty/chromium/extensions/browser/pref_names.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/browser/pref_names.cc
@@ -48,7 +48,7 @@ const char kDeletedComponentExtensions[] =
 const char kDeletedComponentExtensions[] =
     "extensions.deleted_component_extensions";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kChromeAppsEnabled[] = "extensions.chrome_apps_enabled";
 #endif
 const char kU2fSecurityKeyApiEnabled[] =
