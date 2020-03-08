--- chrome/app/chrome_content_browser_overlay_manifest.cc.orig	2020-03-03 18:53:48 UTC
+++ chrome/app/chrome_content_browser_overlay_manifest.cc
@@ -60,7 +60,7 @@
 #include "chrome/browser/ui/webui/app_management/app_management.mojom.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #endif
@@ -145,7 +145,7 @@ const service_manager::Manifest& GetChromeContentBrows
 #else
                 app_management::mojom::PageHandlerFactory,
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
                 discards::mojom::DetailsProvider, discards::mojom::GraphDump,
 #endif
