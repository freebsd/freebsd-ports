--- chrome/browser/ui/hats/survey_config.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/hats/survey_config.cc
@@ -559,7 +559,7 @@ std::vector<hats::SurveyConfig> GetAllSurveyConfigs() 
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<std::string> identity_string_psd_fields{
       "Channel", "Chrome Version", "Number of Chrome Profiles",
       "Number of Google Accounts", "Sign-in Status"};
