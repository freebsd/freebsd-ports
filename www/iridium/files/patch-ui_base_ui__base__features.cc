--- ui/base/ui_base_features.cc.orig	2023-11-22 14:00:11 UTC
+++ ui/base/ui_base_features.cc
@@ -216,7 +216,7 @@ BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -328,7 +328,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -604,7 +604,7 @@ BASE_FEATURE(kBubbleMetricsApi,
              "BubbleMetricsApi",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWebUiSystemFont,
              "WebUiSystemFont",
              base::FEATURE_ENABLED_BY_DEFAULT);
