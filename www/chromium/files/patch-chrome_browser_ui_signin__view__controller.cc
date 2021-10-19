--- chrome/browser/ui/signin_view_controller.cc.orig	2021-09-24 18:29:46 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -240,7 +240,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     const AccountInfo& account_info,
     SkColor profile_color,
     base::OnceCallback<void(bool)> callback) {
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   CloseModalSignin();
   // The delegate will delete itself on request of the UI code when the widget
