--- third_party/WebKit/Source/platform/image-decoders/png/PNGImageDecoder.cpp.orig	2016-05-27 18:46:06.992656000 -0400
+++ third_party/WebKit/Source/platform/image-decoders/png/PNGImageDecoder.cpp	2016-05-27 18:46:37.983471000 -0400
@@ -234,7 +234,7 @@
 #endif
             png_uint_32 profileLength = 0;
             if (png_get_iCCP(png, info, &profileName, &compressionType, &profile, &profileLength)) {
-                setColorProfileAndTransform(profile, profileLength, imageHasAlpha, false /* useSRGB */);
+                setColorProfileAndTransform(reinterpret_cast<const char*>(profile), profileLength, imageHasAlpha, false /* useSRGB */);
             }
         }
 #endif // PNG_iCCP_SUPPORTED
