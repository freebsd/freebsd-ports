--- chrome/browser/ui/views/profiles/first_run_flow_controller.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/profiles/first_run_flow_controller.cc
@@ -67,7 +67,7 @@
 #include "chrome/installer/util/shell_util.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/check_deref.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/global_features.h"
@@ -760,7 +760,7 @@ std::string FirstRunFlowController::GetHatsSurveyTrigg
 }
 
 void FirstRunFlowController::MaybeTriggerHatsSurvey() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No variations seed is available on Mac and Linux at the very first run of
   // Chrome. Check the locale manually to make sure the survey is enabled for
   // only eligible users. Do the locale check before the feature check to avoid
