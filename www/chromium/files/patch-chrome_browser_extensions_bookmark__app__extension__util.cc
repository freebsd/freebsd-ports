--- chrome/browser/extensions/bookmark_app_extension_util.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/extensions/bookmark_app_extension_util.cc
@@ -34,7 +34,7 @@ namespace {
 
 #if !defined(OS_CHROMEOS)
 bool CanOsAddDesktopShortcuts() {
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
