--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2022-10-01 07:40:07 UTC
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -428,7 +428,7 @@ CustomThemeSupplier* AppBrowserController::GetThemeSup
 }
 
 bool AppBrowserController::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
