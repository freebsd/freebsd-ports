--- chrome/browser/ui/passwords/manage_passwords_ui_controller.cc.orig	2024-06-17 12:56:06 UTC
+++ chrome/browser/ui/passwords/manage_passwords_ui_controller.cc
@@ -92,7 +92,7 @@ int ManagePasswordsUIController::save_fallback_timeout
 
 namespace {
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Should be kept in sync with constant declared in
 // bubble_controllers/relaunch_chrome_bubble_controller.cc.
 constexpr int kMaxNumberOfTimesKeychainErrorBubbleIsShown = 3;
@@ -475,7 +475,7 @@ void ManagePasswordsUIController::OnBiometricAuthBefor
 }
 
 void ManagePasswordsUIController::OnKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!dialog_controller_);
   PrefService* prefs =
       Profile::FromBrowserContext(web_contents()->GetBrowserContext())
