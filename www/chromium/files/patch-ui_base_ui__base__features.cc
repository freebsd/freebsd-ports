--- ui/base/ui_base_features.cc.orig	2022-06-17 14:20:10 UTC
+++ ui/base/ui_base_features.cc
@@ -169,7 +169,7 @@ const base::Feature kExperimentalFlingAnimation {
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) ||                                   \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-     !BUILDFLAG(IS_CHROMEOS_LACROS))
+     !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -265,7 +265,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 const base::Feature kEyeDropper {
   "EyeDropper",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
