--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -210,7 +210,7 @@ CONSTINIT const base::Feature kExperimentalFlingAnimat
              "ExperimentalFlingAnimation",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -315,7 +315,7 @@ CONSTINIT const base::Feature kEyeDropper(
 // milestones.
 CONSTINIT const base::Feature kEyeDropper(
              "EyeDropper",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
