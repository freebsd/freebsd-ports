--- chrome/browser/web_applications/components/web_app_shortcut.cc.orig	2020-03-17 09:41:50 UTC
+++ chrome/browser/web_applications/components/web_app_shortcut.cc
@@ -35,7 +35,7 @@ namespace {
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
 const size_t kNumDesiredIconSizesForShortcut =
     base::size(kDesiredIconSizesForShortcut);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
