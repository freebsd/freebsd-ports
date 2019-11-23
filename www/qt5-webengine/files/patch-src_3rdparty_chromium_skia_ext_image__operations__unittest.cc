--- src/3rdparty/chromium/skia/ext/image_operations_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/skia/ext/image_operations_unittest.cc
@@ -18,9 +18,11 @@
 #include "skia/ext/image_operations.h"
 #include "testing/gtest/include/gtest/gtest.h"
 #include "third_party/skia/include/core/SkBitmap.h"
+#include "third_party/skia/include/core/SkColorPriv.h"
 #include "third_party/skia/include/core/SkColorSpace.h"
 #include "third_party/skia/include/core/SkImageInfo.h"
 #include "third_party/skia/include/core/SkRect.h"
+#include "third_party/skia/include/core/SkUnPreMultiply.h"
 #include "ui/gfx/codec/png_codec.h"
 #include "ui/gfx/geometry/size.h"
 
@@ -151,7 +153,7 @@ void DrawCheckerToBitmap(int w, int h,
 
       bool use_color2 = (x_bit != y_bit);  // xor
 
-      *bmp->getAddr32(x, y) = (use_color2 ? color2 : color1);
+      *bmp->getAddr32(x, y) = SkPreMultiplyColor(use_color2 ? color2 : color1);
     }
   }
 }
@@ -273,7 +275,7 @@ void CheckResizeMethodShouldAverageGrid(
         std::max(tested_pixel.max_color_distance,
                  tested_method.max_color_distance_override);
 
-    const SkColor actual_color = *dest.getAddr32(x, y);
+    const SkColor actual_color = SkUnPreMultiply::PMColorToColor(*dest.getAddr32(x, y));
 
     // Check that the pixels away from the border region are very close
     // to the expected average color
@@ -528,7 +530,7 @@ TEST(ImageOperations, ScaleUp) {
   for (int src_y = 0; src_y < src_h; ++src_y) {
     for (int src_x = 0; src_x < src_w; ++src_x) {
       *src.getAddr32(src_x, src_y) =
-          SkColorSetARGB(255, 10 + src_x * 100, 10 + src_y * 100, 0);
+          SkPackARGB32(255, 10 + src_x * 100, 10 + src_y * 100, 0);
     }
   }
 
@@ -552,7 +554,7 @@ TEST(ImageOperations, ScaleUp) {
               lanczos3(src_x + 0.5 - dst_x_in_src) *
               lanczos3(src_y + 0.5 - dst_y_in_src);
           sum += coeff;
-          SkColor tmp = *src.getAddr32(src_x, src_y);
+          SkColor tmp = SkUnPreMultiply::PMColorToColor(*src.getAddr32(src_x, src_y));
           a += coeff * SkColorGetA(tmp);
           r += coeff * SkColorGetR(tmp);
           g += coeff * SkColorGetG(tmp);
@@ -571,7 +573,7 @@ TEST(ImageOperations, ScaleUp) {
       if (r > 255.0f) r = 255.0f;
       if (g > 255.0f) g = 255.0f;
       if (b > 255.0f) b = 255.0f;
-      SkColor dst_color = *dst.getAddr32(dst_x, dst_y);
+      SkColor dst_color = SkUnPreMultiply::PMColorToColor(*dst.getAddr32(dst_x, dst_y));
       EXPECT_LE(fabs(SkColorGetA(dst_color) - a), 1.5f);
       EXPECT_LE(fabs(SkColorGetR(dst_color) - r), 1.5f);
       EXPECT_LE(fabs(SkColorGetG(dst_color) - g), 1.5f);
