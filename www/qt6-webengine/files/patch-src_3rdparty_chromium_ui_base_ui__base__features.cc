--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -179,7 +179,7 @@ const base::Feature kExperimentalFlingAnimation {
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) ||                                   \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-     !BUILDFLAG(IS_CHROMEOS_LACROS))
+     !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -275,7 +275,7 @@ const base::Feature kEyeDropper {
 // milestones.
 const base::Feature kEyeDropper {
   "EyeDropper",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
