--- chrome/browser/feedback/show_feedback_page.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/feedback/show_feedback_page.cc
@@ -30,7 +30,7 @@
 #include "third_party/re2/src/re2/re2.h"
 #include "ui/base/base_window.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/feedback_disabled_dialog.h"
 #endif
 
@@ -264,7 +264,7 @@ void ShowFeedbackPageImpl(gfx::NativeWindow parent,
     return;
   }
   if (!CanSubmitFeedback(profile)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ShowFeedbackDisabledDialog(parent, profile);
 #endif
     base::UmaHistogramEnumeration("Feedback.NotAllowed.RequestSource", source,
@@ -295,7 +295,7 @@ bool CanSubmitFeedback(const Profile* profile) {
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // Incognito profiles should apply the same restrictions as their original
   // profile.
@@ -325,7 +325,7 @@ bool CanShowFeedback(const Profile* profile) {
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kFeedbackDisabledDialog)) {
     return true;
   }
