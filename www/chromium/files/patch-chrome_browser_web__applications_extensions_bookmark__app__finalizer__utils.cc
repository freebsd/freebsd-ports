--- chrome/browser/web_applications/extensions/bookmark_app_finalizer_utils.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/browser/web_applications/extensions/bookmark_app_finalizer_utils.cc
@@ -18,7 +18,7 @@ namespace {
 bool CanOsAddDesktopShortcuts() {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
