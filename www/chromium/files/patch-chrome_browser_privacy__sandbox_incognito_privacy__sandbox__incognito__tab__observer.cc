--- chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.cc
@@ -11,7 +11,7 @@
 #include "privacy_sandbox_incognito_survey_service.h"
 #include "privacy_sandbox_incognito_survey_service_factory.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "privacy_sandbox_whats_new_survey_service.h"
 #include "privacy_sandbox_whats_new_survey_service_factory.h"
 #endif
@@ -40,7 +40,7 @@ void PrivacySandboxIncognitoTabObserver::DidFinishLoad
     return;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // What's new page is fully contained within a single iframe for all the
   // contents. The survey on the "What's New" page should only appear when the
   // *iframe's* content is fully loaded. This happens after the main frame's
@@ -72,7 +72,7 @@ bool PrivacySandboxIncognitoTabObserver::IsNewTabPage(
          url == chrome::kChromeUINewTabURL;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // constant kChromeUIWhatsNewURL is defined only for this three.
 bool PrivacySandboxIncognitoTabObserver::IsWhatsNewPage(const GURL& url) {
   return url == chrome::kChromeUIWhatsNewURL;
