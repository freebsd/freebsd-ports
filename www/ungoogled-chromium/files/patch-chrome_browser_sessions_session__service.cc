--- chrome/browser/sessions/session_service.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/sessions/session_service.cc
@@ -120,7 +120,7 @@ class InstanceTracker : public base::SupportsUserData:
 };
 
 bool ShouldTriggerSessionRestoreForBrowser(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kRespectShouldTriggerSessionRestoreOnDesktop) &&
       browser) {
