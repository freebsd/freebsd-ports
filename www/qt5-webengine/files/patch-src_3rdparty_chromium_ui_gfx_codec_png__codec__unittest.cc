--- src/3rdparty/chromium/ui/gfx/codec/png_codec_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/gfx/codec/png_codec_unittest.cc
@@ -853,7 +853,7 @@ TEST(PNGCodec, EncodeA8SkBitmap) {
     for (int y = 0; y < h; y++) {
       uint8_t original_pixel = *original_bitmap.getAddr8(x, y);
       uint32_t decoded_pixel = *decoded_bitmap.getAddr32(x, y);
-      EXPECT_TRUE(BGRAGrayEqualsA8Gray(decoded_pixel, original_pixel));
+      EXPECT_TRUE(BGRAGrayEqualsA8Gray(SkUnPreMultiply::PMColorToColor(decoded_pixel), original_pixel));
     }
   }
 }
