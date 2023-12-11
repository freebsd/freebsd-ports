--- chrome/browser/web_applications/web_app_install_info.h.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -35,7 +35,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
