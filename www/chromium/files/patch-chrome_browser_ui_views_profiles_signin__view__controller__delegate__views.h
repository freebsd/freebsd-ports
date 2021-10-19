--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2021-09-24 18:32:31 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -62,7 +62,7 @@ class SigninViewControllerDelegateViews
       Browser* browser,
       signin_metrics::ReauthAccessPoint);
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   static std::unique_ptr<views::WebView> CreateEnterpriseConfirmationWebView(
       Browser* browser,
