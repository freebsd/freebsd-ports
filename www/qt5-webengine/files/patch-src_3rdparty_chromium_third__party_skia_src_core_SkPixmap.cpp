--- src/3rdparty/chromium/third_party/skia/src/core/SkPixmap.cpp.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/core/SkPixmap.cpp
@@ -246,7 +246,8 @@ SkColor SkPixmap::getColor(int x, int y) const {
     const bool needsUnpremul = (kPremul_SkAlphaType == fInfo.alphaType());
     auto toColor = [needsUnpremul](uint32_t maybePremulColor) {
         return needsUnpremul ? SkUnPreMultiply::PMColorToColor(maybePremulColor)
-                             : SkSwizzle_BGRA_to_PMColor(maybePremulColor);
+                             : SkColorSetARGB(SkGetPackedA32(maybePremulColor), SkGetPackedR32(maybePremulColor),
+					      SkGetPackedG32(maybePremulColor), SkGetPackedB32(maybePremulColor));
     };
 
     switch (this->colorType()) {
