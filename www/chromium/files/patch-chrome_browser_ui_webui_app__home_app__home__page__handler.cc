--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -61,7 +61,7 @@
 #include "ui/base/window_open_disposition_utils.h"
 #include "url/gurl.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 using content::WebUI;
 using extensions::Extension;
