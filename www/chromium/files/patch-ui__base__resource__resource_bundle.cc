--- ui/base/resource/resource_bundle.cc.orig	2011-04-15 11:02:03.000000000 +0300
+++ ui/base/resource/resource_bundle.cc	2011-04-16 23:02:04.027069500 +0300
@@ -129,7 +129,7 @@
   return *GetEmptyImage();
 }
 
-#if !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_FREEBSD)
 // Only Mac and Linux have non-Skia native image types. All other platforms use
 // Skia natively, so just use GetImageNamed().
 gfx::Image& ResourceBundle::GetNativeImageNamed(int resource_id) {
