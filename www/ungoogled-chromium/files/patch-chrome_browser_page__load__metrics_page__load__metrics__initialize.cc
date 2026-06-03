--- chrome/browser/page_load_metrics/page_load_metrics_initialize.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/page_load_metrics/page_load_metrics_initialize.cc
@@ -69,7 +69,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -361,7 +361,7 @@ bool PageLoadMetricsEmbedder::IsInternalWebUI(const GU
 
 bool PageLoadMetricsEmbedder::ShouldObserveScheme(std::string_view scheme) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return scheme == webapps::kIsolatedAppScheme;
 #else   // !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS))
