--- media/cdm/cdm_paths_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ media/cdm/cdm_paths_unittest.cc
@@ -18,7 +18,7 @@
 // TODO(crbug.com/971433). Move the CDMs out of the install directory on
 // ChromeOS.
 #if (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-     BUILDFLAG(IS_CHROMEOS_LACROS))
+     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #define CDM_USE_PLATFORM_SPECIFIC_PATH
 #endif
 
@@ -39,7 +39,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #else
     "unsupported_platform";
