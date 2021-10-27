--- device/fido/features.cc.orig	2021-09-24 04:26:06 UTC
+++ device/fido/features.cc
@@ -26,7 +26,7 @@ extern const base::Feature kWebAuthCableServerLink {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 // If updating this, also update kWebAuthCable.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
@@ -35,7 +35,7 @@ extern const base::Feature kWebAuthCableServerLink {
 
 extern const base::Feature kWebAuthCableSecondFactor {
   "WebAuthenticationCableSecondFactor",
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_ANDROID)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       // This is default-disabled on Android because it involves changes that
       // alter the interaction with the Sync service and thus needs to be rolled
       // out gradually.
