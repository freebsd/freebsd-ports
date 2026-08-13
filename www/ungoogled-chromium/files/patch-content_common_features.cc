--- content/common/features.cc.orig	2026-08-13 07:41:05 UTC
+++ content/common/features.cc
@@ -209,7 +209,7 @@ BASE_FEATURE(kKillOnUnexpectedOriginHeader, base::FEAT
 BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -320,12 +320,12 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         FontDataServiceTypefaceType::kDwrite,
                         &font_data_service_typeface);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::FeatureParam<FontDataServiceTypefaceType>::Option
     font_data_service_typeface[] = {
         {FontDataServiceTypefaceType::kFreetype, "Freetype"},
         {FontDataServiceTypefaceType::kFontations, "Fontations"}};
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFontDataServiceLinux, base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         kFontDataServiceTypefaceType,
@@ -348,11 +348,11 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
 BASE_FEATURE(kFontDataServiceForCSSLocalFonts,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled() {
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kFontDataServiceAllWebContents);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFontDataServiceLinux);
 #elif BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(features::kFontDataServiceChromeOS);
