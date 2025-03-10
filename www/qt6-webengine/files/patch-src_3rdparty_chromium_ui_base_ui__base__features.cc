--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -217,7 +217,7 @@ BASE_FEATURE(kUiCompositorScrollWithLayers,
 
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
 BASE_FEATURE(kExperimentalFlingAnimation,
@@ -321,7 +321,7 @@ bool IsForcedColorsEnabled() {
 // and Linux. This feature will be released for other platforms in later
 // milestones.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_DISABLED_BY_DEFAULT);
