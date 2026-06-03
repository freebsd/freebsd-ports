--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -113,7 +113,7 @@ BASE_FEATURE(kWaylandPerSurfaceScale,
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
              "WaylandPerSurfaceScale",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -208,7 +208,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists,
 
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -312,7 +312,7 @@ bool IsForcedColorsEnabled() {
 // and Linux. This feature will be released for other platforms in later
 // milestones.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_DISABLED_BY_DEFAULT);
