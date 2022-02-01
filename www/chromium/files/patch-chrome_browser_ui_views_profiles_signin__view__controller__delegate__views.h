--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2021-12-14 11:45:00 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -63,7 +63,7 @@ class SigninViewControllerDelegateViews
       Browser* browser,
       signin_metrics::ReauthAccessPoint);
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   static std::unique_ptr<views::WebView> CreateEnterpriseConfirmationWebView(
       Browser* browser,
