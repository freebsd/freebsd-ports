--- chrome/browser/ui/signin_view_controller.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -242,7 +242,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     SkColor profile_color,
     base::OnceCallback<void(bool)> callback) {
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   CloseModalSignin();
   // The delegate will delete itself on request of the UI code when the widget
   // is closed.
