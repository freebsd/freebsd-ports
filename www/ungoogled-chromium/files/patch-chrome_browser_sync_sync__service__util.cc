--- chrome/browser/sync/sync_service_util.cc.orig	2023-12-23 12:33:28 UTC
+++ chrome/browser/sync/sync_service_util.cc
@@ -9,7 +9,7 @@
 #include "components/sync/base/features.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/variations/service/variations_service.h"
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN)
@@ -22,7 +22,7 @@ bool IsDesktopEnUSLocaleOnlySyncPollFeatureEnabled() {
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::string country_code;
   auto* variations_service = g_browser_process->variations_service();
   if (variations_service) {
