--- components/webapps/browser/features.cc.orig	2024-10-01 07:26:23 UTC
+++ components/webapps/browser/features.cc
@@ -43,7 +43,7 @@ extern const base::FeatureParam<int> kBannerParamsDays
 BASE_FEATURE(kWebAppsEnableMLModelForPromotion,
              "WebAppsEnableMLModelForPromotion",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
