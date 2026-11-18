--- chrome/browser/ui/views/global_media_controls/media_toolbar_button_contextual_menu.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/ui/views/global_media_controls/media_toolbar_button_contextual_menu.cc
@@ -20,7 +20,7 @@
 #include "components/media_router/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/feedback_disabled_dialog.h"
 #endif
 
@@ -120,7 +120,7 @@ void MediaToolbarButtonContextualMenu::ToggleShowOther
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 void MediaToolbarButtonContextualMenu::ReportIssue() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Cast uses its own feedback page (chrome://cast-feedback) instead of the
   // standard feedback dialog. However, when feedback submission is disabled,
   // chrome://cast-feedback is not available; display the FeedbackDisabledDialog
