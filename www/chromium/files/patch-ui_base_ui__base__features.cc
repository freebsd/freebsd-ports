--- ui/base/ui_base_features.cc.orig	2020-05-13 18:40:37 UTC
+++ ui/base/ui_base_features.cc
@@ -121,7 +121,7 @@ const base::Feature kPrecisionTouchpadLogging{
     "PrecisionTouchpadLogging", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -131,7 +131,7 @@ const base::Feature kDirectManipulationStylus = {
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Enables forced colors mode for web content.
 const base::Feature kForcedColors{"ForcedColors",
@@ -157,7 +157,7 @@ bool IsEyeDropperEnabled() {
 // crbug.com/1012106 for the Windows launch bug, and crbug.com/1012108 for the
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_MACOSX)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
