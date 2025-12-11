--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -58,7 +58,7 @@ class SigninViewControllerDelegateViews
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView> CreateHistorySyncOptInWebView(
       Browser* browser,
       HistorySyncOptinLaunchContext launch_context,
@@ -82,7 +82,7 @@ class SigninViewControllerDelegateViews
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView>
   CreateManagedUserNoticeConfirmationWebView(
       Browser* browser,
@@ -153,7 +153,7 @@ class SigninViewControllerDelegateViews
       std::optional<int> dialog_width,
       InitializeSigninWebDialogUI initialize_signin_web_dialog_ui);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deletes the ephemeral profile when cancelling the local profile creation
   // dialog.
   void DeleteProfileOnCancel();
