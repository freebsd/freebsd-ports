--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/graphics_context_test.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/graphics_context_test.cc
@@ -52,7 +52,7 @@ namespace blink {
   {                                                              \
     for (int y = opaqueRect.Y(); y < opaqueRect.MaxY(); ++y)     \
       for (int x = opaqueRect.X(); x < opaqueRect.MaxX(); ++x) { \
-        int alpha = *bitmap.getAddr32(x, y) >> 24;               \
+        int alpha = SkGetPackedA32(*bitmap.getAddr32(x, y));	 \
         EXPECT_EQ(255, alpha);                                   \
       }                                                          \
   }
@@ -61,12 +61,16 @@ namespace blink {
   {                                                           \
     for (int y = 0; y < bitmap.height(); ++y)                 \
       for (int x = 0; x < bitmap.width(); ++x) {              \
-        int alpha = *bitmap.getAddr32(x, y) >> 24;            \
+        int alpha = SkGetPackedA32(*bitmap.getAddr32(x, y));  \
         bool opaque = opaqueRect.Contains(x, y);              \
         EXPECT_EQ(opaque, alpha == 255);                      \
       }                                                       \
   }
 
+static inline uint32_t PackARGB32(uint32_t argb) {
+  return SkPackARGB32NoCheck(argb>>24, (argb<<8)>>24, (argb<<16)>>24, (argb<<24)>>24);
+}
+
 TEST(GraphicsContextTest, Recording) {
   SkBitmap bitmap;
   bitmap.allocN32Pixels(100, 100);
@@ -184,10 +188,10 @@ class GraphicsContextHighConstrastTest : public testin
 TEST_F(GraphicsContextHighConstrastTest, MAYBE_NoHighContrast) {
   DrawColorsToContext();
 
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xffff0000, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xff808080, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xffff0000), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xff808080), *bitmap_.getAddr32(3, 0));
 }
 
 // TODO(crbug.com/850782): Reenable this.
@@ -205,10 +209,10 @@ TEST_F(GraphicsContextHighConstrastTest, MAYBE_HighCon
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xffff0000, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xff808080, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xffff0000), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xff808080), *bitmap_.getAddr32(3, 0));
 }
 
 // Simple invert for testing. Each color component |c|
@@ -228,10 +232,10 @@ TEST_F(GraphicsContextHighConstrastTest, MAYBE_SimpleI
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xff00ffff, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xff7f7f7f, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xff00ffff), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xff7f7f7f), *bitmap_.getAddr32(3, 0));
 }
 
 // Invert brightness (with gamma correction).
@@ -250,10 +254,10 @@ TEST_F(GraphicsContextHighConstrastTest, MAYBE_InvertB
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xff00ffff, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xffdddddd, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xff00ffff), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xffdddddd), *bitmap_.getAddr32(3, 0));
 }
 
 // Invert lightness (in HSL space).
@@ -272,10 +276,10 @@ TEST_F(GraphicsContextHighConstrastTest, MAYBE_InvertL
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xffff0000, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xffdddddd, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xffff0000), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xffdddddd), *bitmap_.getAddr32(3, 0));
 }
 
 // Invert lightness plus grayscale.
@@ -288,10 +292,10 @@ TEST_F(GraphicsContextHighConstrastTest, InvertLightne
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xffe2e2e2, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xffdddddd, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xffe2e2e2), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xffdddddd), *bitmap_.getAddr32(3, 0));
 }
 
 // TODO(crbug.com/850782): Reenable this.
@@ -309,10 +313,10 @@ TEST_F(GraphicsContextHighConstrastTest, MAYBE_InvertL
 
   DrawColorsToContext();
 
-  EXPECT_EQ(0xffffffff, *bitmap_.getAddr32(0, 0));
-  EXPECT_EQ(0xff000000, *bitmap_.getAddr32(1, 0));
-  EXPECT_EQ(0xffff0000, *bitmap_.getAddr32(2, 0));
-  EXPECT_EQ(0xffeeeeee, *bitmap_.getAddr32(3, 0));
+  EXPECT_EQ(PackARGB32(0xffffffff), *bitmap_.getAddr32(0, 0));
+  EXPECT_EQ(PackARGB32(0xff000000), *bitmap_.getAddr32(1, 0));
+  EXPECT_EQ(PackARGB32(0xffff0000), *bitmap_.getAddr32(2, 0));
+  EXPECT_EQ(PackARGB32(0xffeeeeee), *bitmap_.getAddr32(3, 0));
 }
 
 }  // namespace blink
