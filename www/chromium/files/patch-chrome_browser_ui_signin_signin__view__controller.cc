--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2025-04-04 08:52:13 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -428,7 +428,7 @@ void SigninViewController::ShowModalSyncConfirmationDi
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
