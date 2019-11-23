--- src/3rdparty/chromium/ui/gfx/skbitmap_operations_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/gfx/skbitmap_operations_unittest.cc
@@ -238,7 +238,7 @@ TEST(SkBitmapOperationsTest, CreateHSLShiftedBitmapHue
 
   for (int y = 0, i = 0; y < src_h; y++) {
     for (int x = 0; x < src_w; x++) {
-      *src.getAddr32(x, y) = SkColorSetARGB(255, 0, 0, i % 255);
+      *src.getAddr32(x, y) = SkPackARGB32(255, 0, 0, i % 255);
       i++;
     }
   }
