--- chrome/browser/ui/tab_helpers.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -178,7 +178,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/blocked_content/framebust_block_tab_helper.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/hats/hats_helper.h"
@@ -495,13 +495,13 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 
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
@@ -512,7 +512,7 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (Browser* browser = chrome::FindBrowserWithProfile(profile)) {
     SharedHighlightingPromo::CreateForWebContents(web_contents, browser);
   }
