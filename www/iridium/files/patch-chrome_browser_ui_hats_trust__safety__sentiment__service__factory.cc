--- chrome/browser/ui/hats/trust_safety_sentiment_service_factory.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/ui/hats/trust_safety_sentiment_service_factory.cc
@@ -58,7 +58,7 @@ TrustSafetySentimentServiceFactory::BuildServiceInstan
   // TrustSafetySentimentSurvey is conducted only for Windows, MacOS and Linux
   // currently.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS))
 
   // TrustSafetySentimentSurvey is conducted only in English currently.
   static constexpr auto kSurveyLocales =
