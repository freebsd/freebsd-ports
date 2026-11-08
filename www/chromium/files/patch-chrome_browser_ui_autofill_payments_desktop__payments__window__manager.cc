--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -59,7 +59,7 @@ gfx::Size GetPopupSizeForBnpl() {
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(
       ProfileBrowserCollection::GetForProfile(Profile::FromBrowserContext(
           client_->GetWebContents().GetBrowserContext())));
@@ -155,7 +155,7 @@ void DesktopPaymentsWindowManager::WebContentsDestroye
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserActivated(
     BrowserWindowInterface* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
