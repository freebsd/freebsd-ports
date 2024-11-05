--- ui/base/ui_base_features.cc.orig	2024-11-04 08:56:03 UTC
+++ ui/base/ui_base_features.cc
@@ -162,7 +162,7 @@ BASE_FEATURE(kWaylandTextInputV3,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, users not specify --ozone-platform-hint switch
 // will get --ozone-platform-hint=auto treatment. https://crbug.com/40250220.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
@@ -264,7 +264,7 @@ BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -366,7 +366,7 @@ bool IsForcedColorsEnabled() {
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
