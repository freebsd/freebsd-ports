--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -489,7 +489,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
