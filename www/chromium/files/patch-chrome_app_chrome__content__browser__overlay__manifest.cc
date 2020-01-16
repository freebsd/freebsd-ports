--- chrome/app/chrome_content_browser_overlay_manifest.cc.orig	2019-12-16 21:51:22 UTC
+++ chrome/app/chrome_content_browser_overlay_manifest.cc
@@ -70,7 +70,7 @@
 #include "chrome/browser/ui/webui/app_management/app_management.mojom.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #endif
@@ -189,7 +189,7 @@ const service_manager::Manifest& GetChromeContentBrows
 #else
                 app_management::mojom::PageHandlerFactory,
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
                 discards::mojom::DetailsProvider, discards::mojom::GraphDump,
 #endif
