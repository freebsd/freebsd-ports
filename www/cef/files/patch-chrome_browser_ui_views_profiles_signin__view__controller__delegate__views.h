--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -61,7 +61,7 @@ class SigninViewControllerDelegateViews
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView> CreateHistorySyncOptInWebView(
       Browser* browser,
       bool should_close_modal_dialog,
@@ -87,7 +87,7 @@ class SigninViewControllerDelegateViews
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView>
   CreateManagedUserNoticeConfirmationWebView(
       BrowserWindowInterface& browser,
@@ -159,7 +159,7 @@ class SigninViewControllerDelegateViews
       std::optional<int> dialog_width,
       InitializeSigninWebDialogUI initialize_signin_web_dialog_ui);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deletes the ephemeral profile when cancelling the local profile creation
   // dialog.
   void DeleteProfileOnCancel();
