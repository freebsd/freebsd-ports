--- src/3rdparty/chromium/extensions/browser/pref_names.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/browser/pref_names.h
@@ -98,7 +98,7 @@ extern const char kDeletedComponentExtensions[];
 extern const char kDeletedComponentExtensions[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // A preference for whether Chrome Apps should be allowed. The default depends
 // on the ChromeAppsDeprecation feature flag, and this pref can extend support
 // for Chrome Apps by enterprise policy.
