--- chrome/browser/web_applications/components/web_app_shortcut.cc.orig	2020-05-13 18:39:39 UTC
+++ chrome/browser/web_applications/components/web_app_shortcut.cc
@@ -34,7 +34,7 @@ namespace {
 
 #if defined(OS_MACOSX)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
