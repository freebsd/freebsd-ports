--- chrome/browser/ui/webui/app_home/app_home_page_handler.h.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.h
@@ -23,7 +23,7 @@
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 class Browser;
 class ExtensionEnableFlow;
