--- chrome/browser/ui/signin/signin_view_controller.h.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/ui/signin/signin_view_controller.h
@@ -170,7 +170,7 @@ class SigninViewController {
   void ShowModalSyncConfirmationDialog(bool is_signin_intercept,
                                        bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Shows the modal history sync opt in dialog as a browser-modal dialog on top
   // of the `browser_`'s window. Executes the provided callback when the dialog
   // closes.
