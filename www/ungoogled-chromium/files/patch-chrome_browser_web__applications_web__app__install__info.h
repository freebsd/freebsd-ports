--- chrome/browser/web_applications/web_app_install_info.h.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -41,7 +41,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
