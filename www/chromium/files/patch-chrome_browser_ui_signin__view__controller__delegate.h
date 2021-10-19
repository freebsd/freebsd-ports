--- chrome/browser/ui/signin_view_controller_delegate.h.orig	2021-09-24 18:29:25 UTC
+++ chrome/browser/ui/signin_view_controller_delegate.h
@@ -63,7 +63,7 @@ class SigninViewControllerDelegate {
       const CoreAccountId& account_id,
       signin_metrics::ReauthAccessPoint access_point);
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the enterprise confirmation modal dialog. The returned object
