--- src/chrome/browser/ui/hats/survey_config.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/hats/survey_config.cc
@@ -583,7 +583,7 @@ std::vector<hats::SurveyConfig> GetAllSu
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<std::string> identity_string_psd_fields{
       "Channel", "Chrome Version", "Number of Chrome Profiles",
       "Number of Google Accounts", "Sign-in Status"};
