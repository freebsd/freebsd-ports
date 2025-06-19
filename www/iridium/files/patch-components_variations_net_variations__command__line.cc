--- components/variations/net/variations_command_line.cc.orig	2025-06-19 07:37:57 UTC
+++ components/variations/net/variations_command_line.cc
@@ -50,7 +50,7 @@ void ExitWithMessage(const std::string& message) {
 namespace variations {
 
 #if !BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFeedbackIncludeVariations,
              "FeedbackIncludeVariations",
              base::FEATURE_ENABLED_BY_DEFAULT);
