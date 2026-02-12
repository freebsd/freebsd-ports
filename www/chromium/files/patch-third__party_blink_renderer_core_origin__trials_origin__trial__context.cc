--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2026-02-11 09:05:39 UTC
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -563,7 +563,7 @@ bool OriginTrialContext::CanEnableTrialFromName(const 
 
   if (trial_name == "WebAppInstallation") {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(blink::features::kWebAppInstallation);
 #else
     return false;
