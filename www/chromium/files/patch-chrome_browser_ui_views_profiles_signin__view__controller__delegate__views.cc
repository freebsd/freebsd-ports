--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -82,7 +82,7 @@ SigninViewControllerDelegateViews::CreateReauthConfirm
 }
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateEnterpriseConfirmationWebView(
@@ -341,7 +341,7 @@ SigninViewControllerDelegate::CreateReauthConfirmation
 }
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
