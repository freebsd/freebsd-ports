--- chrome/browser/ui/webui/app_home/app_home_page_handler.h.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.h
@@ -24,7 +24,7 @@
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 class ExtensionEnableFlow;
 
