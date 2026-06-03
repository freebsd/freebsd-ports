--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -31,7 +31,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_window/public/browser_window_interface.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -62,7 +62,7 @@ gfx::Rect GetPopupSizeForBnpl() {
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(
       ProfileBrowserCollection::GetForProfile(Profile::FromBrowserContext(
           client_->GetWebContents().GetBrowserContext())));
@@ -157,7 +157,7 @@ void DesktopPaymentsWindowManager::WebContentsDestroye
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserActivated(
     BrowserWindowInterface* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
