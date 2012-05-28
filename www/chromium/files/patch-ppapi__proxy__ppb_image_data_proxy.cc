--- ppapi/proxy/ppb_image_data_proxy.cc.orig	2012-04-25 10:01:26.000000000 +0300
+++ ppapi/proxy/ppb_image_data_proxy.cc	2012-04-29 21:40:17.000000000 +0300
@@ -104,7 +104,7 @@
 ImageHandle ImageData::NullHandle() {
 #if defined(OS_WIN)
   return NULL;
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   return ImageHandle();
 #else
   return 0;
@@ -114,7 +114,7 @@
 ImageHandle ImageData::HandleFromInt(int32_t i) {
 #if defined(OS_WIN)
     return reinterpret_cast<ImageHandle>(i);
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
     return ImageHandle(i, false);
 #else
     return static_cast<ImageHandle>(i);
