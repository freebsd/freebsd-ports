--- chrome/browser/ui/signin/signin_view_controller.h.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/signin/signin_view_controller.h
@@ -169,7 +169,7 @@ class SigninViewController {
   void ShowModalSyncConfirmationDialog(bool is_signin_intercept,
                                        bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Shows the modal history sync opt in dialog as a browser-modal dialog on top
   // of the `browser_`'s window.
   void ShowModalHistorySyncOptInDialog();
