--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -75,7 +75,7 @@ class SigninViewControllerDelegateViews
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView>
   CreateManagedUserNoticeConfirmationWebView(
       Browser* browser,
@@ -141,7 +141,7 @@ class SigninViewControllerDelegateViews
       InitializeSigninWebDialogUI initialize_signin_web_dialog_ui);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Deletes the ephemeral profile when cancelling the local profile creation
   // dialog.
   void DeleteProfileOnCancel();
