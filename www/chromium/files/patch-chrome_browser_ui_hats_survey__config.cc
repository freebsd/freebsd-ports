--- chrome/browser/ui/hats/survey_config.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/hats/survey_config.cc
@@ -365,7 +365,7 @@ std::vector<hats::SurveyConfig> GetAllSurveyConfigs() 
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Scheduled Restart survey.
   // LINT.IfChange(ScheduledRestartHatsPsdFields)
   survey_configs.emplace_back(
