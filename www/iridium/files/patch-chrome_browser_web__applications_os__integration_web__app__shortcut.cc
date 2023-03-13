--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2023-03-13 07:33:08 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -52,7 +52,7 @@ namespace {
 
 #if BUILDFLAG(IS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
