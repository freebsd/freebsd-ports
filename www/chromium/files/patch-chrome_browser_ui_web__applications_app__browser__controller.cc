--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -379,7 +379,7 @@ CustomThemeSupplier* AppBrowserController::GetThemeSup
 }
 
 bool AppBrowserController::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
@@ -387,7 +387,7 @@ bool AppBrowserController::ShouldUseSystemTheme() cons
 }
 
 bool AppBrowserController::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(
       prefs::kUseCustomChromeFrame);
 #else
