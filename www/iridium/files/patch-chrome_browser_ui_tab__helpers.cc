--- chrome/browser/ui/tab_helpers.cc.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -206,7 +206,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/autofill_assistant/common_dependencies_chrome.h"
 #include "chrome/browser/autofill_assistant/platform_dependencies_desktop.h"
 #include "chrome/browser/ui/blocked_content/framebust_block_tab_helper.h"
@@ -547,13 +547,13 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kHappinessTrackingSurveysForDesktopDemo) ||
       base::FeatureList::IsEnabled(features::kTrustSafetySentimentSurvey) ||
@@ -576,7 +576,7 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           autofill_assistant::features::kAutofillAssistantDesktop)) {
     autofill_assistant::CreateForWebContents(
