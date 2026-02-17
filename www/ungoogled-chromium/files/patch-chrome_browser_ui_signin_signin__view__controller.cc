--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -512,7 +512,7 @@ void SigninViewController::ShowModalSyncConfirmationDi
       GetOnModalDialogClosedCallback());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewController::ShowModalHistorySyncOptInDialog(
     bool should_close_modal_dialog,
     HistorySyncOptinHelper::FlowCompletedCallback callback) {
@@ -530,7 +530,7 @@ void SigninViewController::ShowModalHistorySyncOptInDi
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
