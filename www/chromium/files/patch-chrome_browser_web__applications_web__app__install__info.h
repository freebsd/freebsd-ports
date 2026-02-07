--- chrome/browser/web_applications/web_app_install_info.h.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/web_applications/web_app_install_info.h
@@ -42,7 +42,7 @@
 #include "url/gurl.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 namespace web_app {
 
