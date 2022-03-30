--- device/fido/features.cc.orig	2022-03-28 18:11:04 UTC
+++ device/fido/features.cc
@@ -24,7 +24,7 @@ extern const base::Feature kWebAuthCableSecondFactor {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 // If updating this, also update kWebAuthCableServerLink.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
