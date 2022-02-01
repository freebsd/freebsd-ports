--- chrome/browser/ui/signin_view_controller.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -241,7 +241,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     const AccountInfo& account_info,
     SkColor profile_color,
     base::OnceCallback<void(bool)> callback) {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   CloseModalSignin();
   // The delegate will delete itself on request of the UI code when the widget
