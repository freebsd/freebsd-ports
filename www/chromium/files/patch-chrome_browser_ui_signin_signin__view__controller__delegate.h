--- chrome/browser/ui/signin/signin_view_controller_delegate.h.orig	2025-03-05 08:14:56 UTC
+++ chrome/browser/ui/signin/signin_view_controller_delegate.h
@@ -79,7 +79,7 @@ class SigninViewControllerDelegate {
       base::OnceCallback<void(ChromeSignoutConfirmationChoice)> callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the managed user notice modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
