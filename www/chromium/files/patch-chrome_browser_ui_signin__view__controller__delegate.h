--- chrome/browser/ui/signin_view_controller_delegate.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/signin_view_controller_delegate.h
@@ -64,7 +64,7 @@ class SigninViewControllerDelegate {
       signin_metrics::ReauthAccessPoint access_point);
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the enterprise confirmation modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
