--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -138,7 +138,7 @@ SigninViewControllerDelegateViews::CreateProfileCustom
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateEnterpriseConfirmationWebView(
@@ -417,7 +417,7 @@ SigninViewControllerDelegate::CreateProfileCustomizati
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
