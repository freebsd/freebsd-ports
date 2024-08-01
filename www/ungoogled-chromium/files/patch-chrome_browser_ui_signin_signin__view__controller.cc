--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -482,7 +482,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
     signin::SigninChoiceCallback process_user_choice_callback,
     base::OnceClosure done_callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
