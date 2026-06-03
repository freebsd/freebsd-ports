--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h
@@ -14,7 +14,7 @@
 #include "components/autofill/core/browser/payments/payments_window_manager.h"
 #include "content/public/browser/web_contents_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/ui/browser_window/public/browser_collection_observer.h"  // nogncheck
 #include "chrome/browser/ui/browser_window/public/profile_browser_collection.h"  // nogncheck
@@ -41,7 +41,7 @@ class PaymentsWindowUserConsentDialogControllerImpl;
 // WebContents of the original tab that the pop-up is created in. If there is a
 // pop-up currently present, `this` will observe the WebContents of that pop-up.
 class DesktopPaymentsWindowManager : public PaymentsWindowManager,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                      public BrowserCollectionObserver,
 #endif  // BUILDFLAG(IS_LINUX)
                                      public content::WebContentsObserver {
@@ -61,7 +61,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
       content::NavigationHandle* navigation_handle) override;
   void WebContentsDestroyed() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // BrowserCollectionObserver:
   void OnBrowserActivated(BrowserWindowInterface* browser) override;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -132,7 +132,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
   // Used in tests to notify the test infrastructure that the pop-up has closed.
   base::RepeatingClosure popup_closed_closure_for_testing_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ProfileBrowserCollection, BrowserCollectionObserver>
       scoped_observation_{this};
 #endif  // BUILDFLAG(IS_LINUX)
