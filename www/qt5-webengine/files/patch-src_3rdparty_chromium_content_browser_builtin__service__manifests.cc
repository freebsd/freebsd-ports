--- src/3rdparty/chromium/content/browser/builtin_service_manifests.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/browser/builtin_service_manifests.cc
@@ -32,7 +32,7 @@
 #include "services/tracing/manifest.h"
 #include "services/video_capture/public/cpp/manifest.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/manifest.h"  // nogncheck
 #endif
 
@@ -99,7 +99,7 @@ const std::vector<service_manager::Manifest>& GetBuilt
                   : service_manager::Manifest::ExecutionMode::
                         kInProcessBuiltin),
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
           font_service::GetManifest(),
 #endif
 #if defined(OS_CHROMEOS)
