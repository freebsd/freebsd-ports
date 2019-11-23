--- src/3rdparty/chromium/ui/gfx/color_analysis.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/gfx/color_analysis.cc
@@ -16,6 +16,7 @@
 #include <vector>
 
 #include "base/logging.h"
+#include "base/sys_byteorder.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkUnPreMultiply.h"
 #include "ui/gfx/codec/png_codec.h"
@@ -506,10 +507,17 @@ SkColor FindClosestColor(const uint8_t* image,
   SkColor best_color = color;
   const uint8_t* byte = image;
   for (int i = 0; i < width * height; ++i) {
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
     uint8_t b = *(byte++);
     uint8_t g = *(byte++);
     uint8_t r = *(byte++);
     uint8_t a = *(byte++);
+#else
+    uint8_t a = *(byte++);
+    uint8_t r = *(byte++);
+    uint8_t g = *(byte++);
+    uint8_t b = *(byte++);
+#endif
     // Ignore fully transparent pixels.
     if (a == 0)
       continue;
@@ -527,7 +535,6 @@ SkColor FindClosestColor(const uint8_t* image,
 
 // For a 16x16 icon on an Intel Core i5 this function takes approximately
 // 0.5 ms to run.
-// TODO(port): This code assumes the CPU architecture is little-endian.
 SkColor CalculateKMeanColorOfBuffer(uint8_t* decoded_data,
                                     int img_width,
                                     int img_height,
@@ -550,10 +557,17 @@ SkColor CalculateKMeanColorOfBuffer(uint8_t* decoded_d
         int pixel_pos = sampler->GetSample(img_width, img_height) %
             (img_width * img_height);
 
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
         uint8_t b = decoded_data[pixel_pos * 4];
         uint8_t g = decoded_data[pixel_pos * 4 + 1];
         uint8_t r = decoded_data[pixel_pos * 4 + 2];
         uint8_t a = decoded_data[pixel_pos * 4 + 3];
+#else
+        uint8_t a = decoded_data[pixel_pos * 4];
+        uint8_t r = decoded_data[pixel_pos * 4 + 1];
+        uint8_t g = decoded_data[pixel_pos * 4 + 2];
+        uint8_t b = decoded_data[pixel_pos * 4 + 3];
+#endif
         // Skip fully transparent pixels as they usually contain black in their
         // RGB channels but do not contribute to the visual image.
         if (a == 0)
@@ -602,10 +616,17 @@ SkColor CalculateKMeanColorOfBuffer(uint8_t* decoded_d
       uint8_t* pixel = decoded_data;
       uint8_t* decoded_data_end = decoded_data + (img_width * img_height * 4);
       while (pixel < decoded_data_end) {
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
         uint8_t b = *(pixel++);
         uint8_t g = *(pixel++);
         uint8_t r = *(pixel++);
         uint8_t a = *(pixel++);
+#else
+        uint8_t a = *(pixel++);
+        uint8_t r = *(pixel++);
+        uint8_t g = *(pixel++);
+        uint8_t b = *(pixel++);
+#endif
         // Skip transparent pixels, see above.
         if (a == 0)
           continue;
@@ -683,8 +704,12 @@ SkColor CalculateKMeanColorOfPNG(scoped_refptr<base::R
 
   if (png.get() && png->size() &&
       gfx::PNGCodec::Decode(png->front(), png->size(),
-                            gfx::PNGCodec::FORMAT_BGRA, &decoded_data,
-                            &img_width, &img_height)) {
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
+                            gfx::PNGCodec::FORMAT_BGRA,
+#else
+                            gfx::PNGCodec::FORMAT_ARGB,
+#endif
+			    &decoded_data, &img_width, &img_height)) {
     return CalculateKMeanColorOfBuffer(&decoded_data[0], img_width, img_height,
                                        lower_bound, upper_bound, sampler, true);
   }
