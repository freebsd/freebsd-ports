--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -135,7 +135,7 @@ bool AreF11AndF12ShortcutsEnabled() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRedundantImeCompositionClearing,
              "RedundantImeCompositionClearing",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -234,7 +234,7 @@ CONSTINIT const base::Feature kExperimentalFlingAnimat
              "ExperimentalFlingAnimation",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -346,7 +346,7 @@ CONSTINIT const base::Feature kEyeDropper(
 // milestones.
 CONSTINIT const base::Feature kEyeDropper(
              "EyeDropper",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -565,7 +565,7 @@ ChromeRefresh2023Level GetChromeRefresh2023Level() {
   return level;
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWebUiSystemFont,
              "WebUiSystemFont",
              base::FEATURE_ENABLED_BY_DEFAULT);
