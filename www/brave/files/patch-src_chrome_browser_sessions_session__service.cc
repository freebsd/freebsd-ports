--- src/chrome/browser/sessions/session_service.cc.orig	2026-10-20 12:27:58 UTC
+++ src/chrome/browser/sessions/session_service.cc
@@ -120,7 +120,7 @@ class InstanceTracker : public base::Sup
 };
 
 bool ShouldTriggerSessionRestoreForBrowser(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kRespectShouldTriggerSessionRestoreOnDesktop) &&
       browser) {
