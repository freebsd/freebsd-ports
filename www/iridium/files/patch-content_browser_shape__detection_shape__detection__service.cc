--- content/browser/shape_detection/shape_detection_service.cc.orig	2025-12-10 15:04:57 UTC
+++ content/browser/shape_detection/shape_detection_service.cc
@@ -15,7 +15,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
 #include "content/public/browser/service_process_host.h"
 #else
 #include "content/browser/gpu/gpu_process_host.h"
@@ -29,7 +29,7 @@ shape_detection::mojom::ShapeDetectionService* GetShap
       remote;
   if (!*remote) {
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
     ServiceProcessHost::Launch<shape_detection::mojom::ShapeDetectionService>(
         remote->BindNewPipeAndPassReceiver(),
         ServiceProcessHost::Options()
