--- chrome/browser/ui/hats/survey_config.h.orig	2025-11-06 10:11:34 UTC
+++ chrome/browser/ui/hats/survey_config.h
@@ -89,7 +89,7 @@ extern const char kHatsSurveyTriggerSafetyHubAndroid[]
 extern const char kHatsSurveyOrganicTriggerSafetyHubAndroid[];
 #endif  // #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kHatsSurveyTriggerPrivacySandboxWhatsNewSurvey[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
