--- ui/views/views_features.cc.orig	2026-08-12 09:02:10 UTC
+++ ui/views/views_features.cc
@@ -50,7 +50,7 @@ BASE_FEATURE(kKeyboardAccessibleTooltipInViews,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Uses NativeViewHostAuraWithClipWindow instead of NativeViewHostAura.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseNativeViewHostAuraWithClipWindow,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #else
