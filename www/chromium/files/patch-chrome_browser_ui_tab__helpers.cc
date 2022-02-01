--- chrome/browser/ui/tab_helpers.cc.orig	2022-01-20 10:35:51 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -170,7 +170,7 @@
 #include "chrome/browser/chromeos/policy/dlp/dlp_content_tab_helper.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 #include "chrome/browser/ui/blocked_content/framebust_block_tab_helper.h"
 #include "chrome/browser/ui/browser_finder.h"
@@ -459,11 +459,11 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (base::FeatureList::IsEnabled(
           features::kHappinessTrackingSurveysForDesktopDemo) ||
@@ -474,7 +474,7 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
   }
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (Browser* browser = chrome::FindBrowserWithProfile(profile)) {
     SharedHighlightingPromo::CreateForWebContents(web_contents, browser);
