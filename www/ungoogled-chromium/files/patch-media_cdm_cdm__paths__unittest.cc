--- media/cdm/cdm_paths_unittest.cc.orig	2022-10-01 07:40:07 UTC
+++ media/cdm/cdm_paths_unittest.cc
@@ -27,7 +27,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #else
 #error unsupported platform
