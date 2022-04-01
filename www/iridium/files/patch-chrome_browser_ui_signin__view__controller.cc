--- chrome/browser/ui/signin_view_controller.cc.orig	2022-04-01 07:48:30 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -259,7 +259,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     SkColor profile_color,
     base::OnceCallback<void(bool)> callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
