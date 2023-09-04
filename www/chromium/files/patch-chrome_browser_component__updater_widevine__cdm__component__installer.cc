--- chrome/browser/component_updater/widevine_cdm_component_installer.cc.orig	2023-09-04 16:07:23 UTC
+++ chrome/browser/component_updater/widevine_cdm_component_installer.cc
@@ -72,6 +72,8 @@ const char kWidevineCdmPlatform[] =
     "cros";
 #elif BUILDFLAG(IS_LINUX)
     "linux";
+#elif BUILDFLAG(IS_FREEBSD)
+    "linux";
 #else
 #error This file should only be included for supported platforms.
 #endif
