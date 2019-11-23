--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/webgl_image_conversion_test.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/webgl_image_conversion_test.cc
@@ -76,9 +76,9 @@ TEST_F(WebGLImageConversionTest, convertBGRA8toRGBA8) 
                              0x34567888, 0x12345678, 0x34567888,
                              0x12345678, 0x34567888, 0x12345678};
 #if defined(ARCH_CPU_BIG_ENDIAN)
-  uint32_t expectedData[9] = {0x56341278, 0x78563488, 0x56341278,
-                              0x78563488, 0x56341278, 0x78563488,
-                              0x56341278, 0x78563488, 0x56341278};
+  uint32_t expected_data[9] = {0x56341278, 0x78563488, 0x56341278,
+			       0x78563488, 0x56341278, 0x78563488,
+			       0x56341278, 0x78563488, 0x56341278};
 #else
   uint32_t expected_data[9] = {0x12785634, 0x34887856, 0x12785634,
                                0x34887856, 0x12785634, 0x34887856,
