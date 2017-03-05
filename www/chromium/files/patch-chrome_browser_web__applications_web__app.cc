--- chrome/browser/web_applications/web_app.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/browser/web_applications/web_app.cc
@@ -58,7 +58,7 @@ namespace {
 #if defined(OS_MACOSX)
 const int kDesiredSizes[] = {16, 32, 128, 256, 512};
 const size_t kNumDesiredSizes = arraysize(kDesiredSizes);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredSizes[] = {16, 32, 48, 128, 256, 512};
@@ -507,7 +507,7 @@ void GetIconsInfo(const WebApplicationIn
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   base::i18n::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
