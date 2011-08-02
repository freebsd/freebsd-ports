--- ppapi/proxy/ppb_image_data_proxy.cc.orig	2011-06-28 23:59:12.540806582 +0300
+++ ppapi/proxy/ppb_image_data_proxy.cc	2011-06-28 23:59:15.075806980 +0300
@@ -111,7 +111,7 @@
 
 #if defined(OS_WIN)
 const ImageHandle ImageData::NullHandle = NULL;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
 const ImageHandle ImageData::NullHandle = ImageHandle();
 #else
 const ImageHandle ImageData::NullHandle = 0;
@@ -120,7 +120,7 @@
 ImageHandle ImageData::HandleFromInt(int32_t i) {
 #if defined(OS_WIN)
     return reinterpret_cast<ImageHandle>(i);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     return ImageHandle(i, false);
 #else
     return static_cast<ImageHandle>(i);
