--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2025-03-05 08:14:56 UTC
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -566,7 +566,7 @@ bool OriginTrialContext::CanEnableTrialFromName(const 
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kTranslationAPI);
 #else
     return false;
