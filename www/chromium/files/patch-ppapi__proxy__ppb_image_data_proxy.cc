--- ppapi/proxy/ppb_image_data_proxy.cc.orig	2012-02-21 10:34:02.000000000 +0200
+++ ppapi/proxy/ppb_image_data_proxy.cc	2012-02-27 18:16:23.000000000 +0200
@@ -83,7 +83,7 @@
 
 #if defined(OS_WIN)
 const ImageHandle ImageData::NullHandle = NULL;
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 const ImageHandle ImageData::NullHandle = ImageHandle();
 #else
 const ImageHandle ImageData::NullHandle = 0;
@@ -92,7 +92,7 @@
 ImageHandle ImageData::HandleFromInt(int32_t i) {
 #if defined(OS_WIN)
     return reinterpret_cast<ImageHandle>(i);
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
     return ImageHandle(i, false);
 #else
     return static_cast<ImageHandle>(i);
