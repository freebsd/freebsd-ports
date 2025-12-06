--- media/gpu/chromeos/gl_image_processor_backend.cc.orig	2025-12-05 10:12:50 UTC
+++ media/gpu/chromeos/gl_image_processor_backend.cc
@@ -29,6 +29,10 @@
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/ozone/public/surface_factory_ozone.h"
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
 namespace media {
 
 namespace {
