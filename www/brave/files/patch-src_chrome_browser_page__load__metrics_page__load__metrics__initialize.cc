--- src/chrome/browser/page_load_metrics/page_load_metrics_initialize.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/page_load_metrics/page_load_metrics_initialize.cc
@@ -83,7 +83,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -432,7 +432,7 @@ bool PageLoadMetricsEmbedder::IsInternal
 
 bool PageLoadMetricsEmbedder::ShouldObserveScheme(std::string_view scheme) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return scheme == webapps::kIsolatedAppScheme;
 #else   // !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS))
