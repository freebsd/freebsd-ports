--- chrome/browser/feedback/show_feedback_page.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/feedback/show_feedback_page.cc
@@ -255,7 +255,7 @@ bool CanShowFeedback(const Profile* profile) {
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // Incognito profiles should apply the same restrictions as their original
   // profile.
