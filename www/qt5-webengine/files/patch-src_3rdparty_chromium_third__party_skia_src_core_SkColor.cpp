--- src/3rdparty/chromium/third_party/skia/src/core/SkColor.cpp.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/core/SkColor.cpp
@@ -108,13 +108,29 @@ SkColor SkHSVToColor(U8CPU a, const SkScalar hsv[3]) {
 template <>
 SkColor4f SkColor4f::FromColor(SkColor bgra) {
     SkColor4f rgba;
-    swizzle_rb(Sk4f_fromL32(bgra)).store(rgba.vec());
+    Sk4f c4f = Sk4f_fromL32(bgra);
+#ifdef SK_CPU_BENDIAN
+    // ARGB -> RGBA
+    c4f = SkNx_shuffle<1, 2, 3, 0>(c4f);
+#else
+    // BGRA -> RGBA
+    c4f = swizzle_rb(c4f);
+#endif
+    c4f.store(rgba.vec());
     return rgba;
 }
 
 template <>
 SkColor SkColor4f::toSkColor() const {
-    return Sk4f_toL32(swizzle_rb(Sk4f::Load(this->vec())));
+    Sk4f c4f = Sk4f::Load(this->vec());
+#ifdef SK_CPU_BENDIAN
+    // RGBA -> ARGB
+    c4f = SkNx_shuffle<3, 0, 1, 2>(c4f);
+#else
+    // RGBA -> BGRA
+    c4f = swizzle_rb(c4f);
+#endif
+    return Sk4f_toL32(c4f);
 }
 
 template <>
