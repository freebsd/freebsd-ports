--- content/common/features.cc.orig	2026-02-11 09:05:39 UTC
+++ content/common/features.cc
@@ -172,7 +172,7 @@ BASE_FEATURE(kDocumentPolicyNegotiation, base::FEATURE
 BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -276,7 +276,7 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         FontDataServiceTypefaceType::kDwrite,
                         &font_data_service_typeface);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFontDataServiceLinux, base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<FontDataServiceTypefaceType>::Option
     font_data_service_typeface[] = {
@@ -290,11 +290,11 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         &font_data_service_typeface);
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled() {
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kFontDataServiceAllWebContents);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFontDataServiceLinux);
 #else
   return false;
