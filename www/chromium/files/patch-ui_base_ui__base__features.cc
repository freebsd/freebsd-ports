--- ui/base/ui_base_features.cc.orig	2026-10-18 13:29:39 UTC
+++ ui/base/ui_base_features.cc
@@ -129,7 +129,7 @@ BASE_FEATURE(kWaylandExternalBeginFrameSource,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kGlobalShortcutsPortalPreferredTrigger,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -185,7 +185,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists, base::FEATUR
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -262,7 +262,7 @@ bool IsTouchTextEditingRedesignEnabled() {
 // This feature enables drag and drop using touch input devices.
 BASE_FEATURE(kTouchDragAndDrop,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -289,7 +289,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -511,7 +511,7 @@ BASE_FEATURE(kChromeDarkNeutrals26, base::FEATURE_DISA
 
 BASE_FEATURE(kDarkModeSurfaceTokens, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
