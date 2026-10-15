--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h
@@ -15,7 +15,7 @@
 #include "content/public/browser/web_contents_observer.h"
 #include "ui/gfx/geometry/size.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/ui/browser_window/public/browser_collection_observer.h"  // nogncheck
 #include "chrome/browser/ui/browser_window/public/profile_browser_collection.h"  // nogncheck
@@ -42,7 +42,7 @@ class PaymentsWindowUserConsentDialogControllerImpl;
 // WebContents of the original tab that the pop-up is created in. If there is a
 // pop-up currently present, `this` will observe the WebContents of that pop-up.
 class DesktopPaymentsWindowManager : public PaymentsWindowManager,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                      public BrowserCollectionObserver,
 #endif  // BUILDFLAG(IS_LINUX)
                                      public content::WebContentsObserver {
@@ -62,7 +62,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
       content::NavigationHandle* navigation_handle) override;
   void WebContentsDestroyed() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // BrowserCollectionObserver:
   void OnBrowserActivated(BrowserWindowInterface* browser) override;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -133,7 +133,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
   // Used in tests to notify the test infrastructure that the pop-up has closed.
   base::RepeatingClosure popup_closed_closure_for_testing_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ProfileBrowserCollection, BrowserCollectionObserver>
       scoped_observation_{this};
 #endif  // BUILDFLAG(IS_LINUX)
