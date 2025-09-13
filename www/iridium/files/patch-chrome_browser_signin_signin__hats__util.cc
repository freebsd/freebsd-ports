--- chrome/browser/signin/signin_hats_util.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/signin/signin_hats_util.cc
@@ -36,7 +36,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -153,7 +153,7 @@ SurveyStringData GetSigninSurveyStringData(
 namespace signin {
 
 bool IsFeatureEnabledForSigninHatsTrigger(const std::string& trigger) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   for (const auto& entry : kChromeIdentityHatsTriggerFeatureMapping) {
     if (trigger == entry.trigger) {
       return base::FeatureList::IsEnabled(*entry.feature);
@@ -171,7 +171,7 @@ void LaunchSigninHatsSurveyForProfile(const std::strin
                                       bool defer_if_no_browser,
                                       std::optional<signin_metrics::AccessPoint>
                                           access_point_for_data_type_promo) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsFeatureEnabledForSigninHatsTrigger(trigger)) {
     return;
   }
