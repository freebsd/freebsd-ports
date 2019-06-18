--- content/public/app/content_packaged_services_manifest.cc.orig	2019-03-11 22:00:58 UTC
+++ content/public/app/content_packaged_services_manifest.cc
@@ -23,7 +23,7 @@
 #include "services/video_capture/manifest.h"
 #include "services/viz/manifest.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/manifest.h"
 #endif
 
@@ -67,7 +67,7 @@ const service_manager::Manifest& GetContentPackagedSer
         .PackageService(tracing::GetManifest())
         .PackageService(video_capture::GetManifest())
         .PackageService(viz::GetManifest())
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         .PackageService(font_service::GetManifest())
 #endif
 #if defined(OS_CHROMEOS)
