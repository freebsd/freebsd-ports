--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -46,7 +46,7 @@ gfx::Rect GetPopupSizeForVcn3ds() {
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(BrowserList::GetInstance());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 }
@@ -106,7 +106,7 @@ void DesktopPaymentsWindowManager::WebContentsDestroye
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserSetLastActive(Browser* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
   // original tab's WebContents become active, activate the pop-up's
