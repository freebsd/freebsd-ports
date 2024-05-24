--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2024-05-23 20:04:36 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -325,7 +325,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
     bool show_link_data_option,
     signin::SigninChoiceCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
