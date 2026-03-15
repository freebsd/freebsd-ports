--- chrome/browser/signin/signin_hats_util.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/signin/signin_hats_util.cc
@@ -42,7 +42,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -215,7 +215,7 @@ void LaunchHatsSurveyForProfileInternal(
     Profile* profile,
     bool defer_if_no_browser,
     base::OnceCallback<SurveyStringData()> data_factory) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsSurveyEnabledForHatsTrigger(trigger)) {
     return;
   }
@@ -260,7 +260,7 @@ void LaunchHatsSurveyForProfile(const std::string& tri
                                     access_point_for_data_type_promo) {
   LaunchHatsSurveyForProfileInternal(
       trigger, profile, defer_if_no_browser,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::BindOnce(&GetSurveyStringData, trigger, profile,
                      access_point_for_data_type_promo)
 #else
