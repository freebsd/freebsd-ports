--- chrome/browser/web_applications/web_app_helpers.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/web_applications/web_app_helpers.cc
@@ -145,7 +145,7 @@ bool IsValidWebAppUrl(const GURL& app_url) {
     return false;
 
   bool allow_extension_apps = true;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Stop allowing apps to be extension urls when the shortcuts are separated -
   // they can be extension urls instead.
   allow_extension_apps =
