--- chrome/browser/chrome_browser_field_trials.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -47,7 +47,7 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -103,7 +103,7 @@ void ChromeBrowserFieldTrials::RegisterFeatureOverride
     base::FeatureList* feature_list) {
   variations::FeatureOverrides feature_overrides(*feature_list);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux/Desktop platform variants, such as ozone/wayland, some features
   // might need to be disabled as per OzonePlatform's runtime properties.
   // OzonePlatform selection and initialization, in turn, depend on Chrome flags
