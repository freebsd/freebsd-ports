--- chrome/browser/web_applications/web_app_install_info.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -36,7 +36,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD));
 
 class SkBitmap;
 
