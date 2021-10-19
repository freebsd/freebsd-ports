--- ui/base/ui_base_features.cc.orig	2021-09-14 01:52:22 UTC
+++ ui/base/ui_base_features.cc
@@ -130,7 +130,7 @@ const base::Feature kExperimentalFlingAnimation {
   "ExperimentalFlingAnimation",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if defined(OS_WIN) || defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
                         !BUILDFLAG(IS_CHROMEOS_LACROS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -213,7 +213,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 const base::Feature kEyeDropper {
   "EyeDropper",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
