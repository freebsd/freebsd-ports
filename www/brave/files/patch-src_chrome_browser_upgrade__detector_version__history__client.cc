--- src/chrome/browser/upgrade_detector/version_history_client.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/upgrade_detector/version_history_client.cc
@@ -177,7 +177,7 @@ GURL GetVersionReleasesUrl(base::Version
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
