--- chrome/browser/ui/hats/survey_config.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/ui/hats/survey_config.cc
@@ -546,7 +546,7 @@ std::vector<hats::SurveyConfig> GetAllSurveyConfigs() 
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<std::string> identity_string_psd_fields{
       "Channel", "Chrome Version", "Number of Chrome Profiles",
       "Number of Google Accounts", "Sign-in Status"};
