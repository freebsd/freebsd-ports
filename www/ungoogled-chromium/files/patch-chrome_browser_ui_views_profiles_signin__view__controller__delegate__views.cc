--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2023-09-17 07:59:53 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -49,7 +49,7 @@ namespace {
 
 const int kModalDialogWidth = 448;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 const int kEnterpriseConfirmationDialogWidth = 512;
 const int kEnterpriseConfirmationDialogHeight = 576;
 #endif
@@ -167,7 +167,7 @@ SigninViewControllerDelegateViews::CreateProfileCustom
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateEnterpriseConfirmationWebView(
@@ -442,7 +442,7 @@ SigninViewControllerDelegate::CreateProfileCustomizati
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
