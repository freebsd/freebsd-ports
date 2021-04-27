--- ui/base/ui_base_features.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/ui_base_features.cc
@@ -127,7 +127,7 @@ const base::Feature kExperimentalFlingAnimation {
   "ExperimentalFlingAnimation",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if defined(OS_WIN) || defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
                         !BUILDFLAG(IS_CHROMEOS_LACROS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -160,7 +160,7 @@ const base::Feature kPrecisionTouchpadLogging{
     "PrecisionTouchpadLogging", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
@@ -171,7 +171,7 @@ const base::Feature kDirectManipulationStylus = {
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 // Enables forced colors mode for web content.
@@ -205,7 +205,7 @@ bool IsEyeDropperEnabled() {
 // crbug.com/1086530 for the Desktop launch bug.
 const base::Feature kCSSColorSchemeUARendering = {
     "CSSColorSchemeUARendering",
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_APPLE)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -224,7 +224,7 @@ bool IsCSSColorSchemeUARenderingEnabled() {
 // crbug.com/1012106 for the Windows launch bug, and crbug.com/1012108 for the
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_APPLE)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
