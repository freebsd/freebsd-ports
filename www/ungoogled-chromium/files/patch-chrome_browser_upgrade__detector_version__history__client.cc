--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -176,7 +176,7 @@ GURL GetVersionReleasesUrl(base::Version version) {
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
