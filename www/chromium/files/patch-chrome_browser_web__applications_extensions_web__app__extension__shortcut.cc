--- chrome/browser/web_applications/extensions/web_app_extension_shortcut.cc.orig	2019-12-16 21:51:24 UTC
+++ chrome/browser/web_applications/extensions/web_app_extension_shortcut.cc
@@ -51,7 +51,7 @@ namespace {
 #if defined(OS_MACOSX)
 const int kDesiredSizes[] = {16, 32, 128, 256, 512};
 const size_t kNumDesiredSizes = base::size(kDesiredSizes);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredSizes[] = {16, 32, 48, 128, 256, 512};
