--- ui/views/views_features.cc.orig	2026-08-31 10:59:09 UTC
+++ ui/views/views_features.cc
@@ -50,7 +50,7 @@ BASE_FEATURE(kKeyboardAccessibleTooltipInViews,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // If enabled, NativeViewHost controls the layers of the native view.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kNativeViewHostManagesLayers, base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kNativeViewHostManagesLayers, base::FEATURE_DISABLED_BY_DEFAULT);
