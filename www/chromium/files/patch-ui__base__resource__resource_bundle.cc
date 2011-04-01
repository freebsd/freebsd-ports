--- ui/base/resource/resource_bundle.cc.orig	2011-01-26 10:31:08.000000000 +0100
+++ ui/base/resource/resource_bundle.cc	2011-01-30 00:45:39.000000000 +0100
@@ -176,7 +176,7 @@
 #if defined(OS_MACOSX)
   return rb.GetNSImageNamed(resource_id);
 #elif defined(USE_X11) && !defined(TOOLKIT_VIEWS)
-  return rb.GetPixbufNamed(resource_id);
+  return (gfx::NativeImage)rb.GetPixbufNamed(resource_id);
 #else
   return rb.GetBitmapNamed(resource_id);
 #endif
