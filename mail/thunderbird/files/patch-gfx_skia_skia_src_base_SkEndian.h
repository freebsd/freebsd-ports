diff --git gfx/skia/skia/src/base/SkEndian.h gfx/skia/skia/src/base/SkEndian.h
index d015f8bff2bf..cc390a53f30c 100644
--- gfx/skia/skia/src/base/SkEndian.h
+++ gfx/skia/skia/src/base/SkEndian.h
@@ -140,7 +140,7 @@ static inline void SkEndianSwap64s(uint64_t array[], int count) {
     #define SkEndian_SwapLE64(n)    SkEndianSwap64(n)
 
     #define SkTEndian_SwapBE16(n)    (n)
-    #define SkTEndian_SwapBE32(n)    (n)
+    #define SkTEndian_SwapBE32(n)    uint32_t(n)
     #define SkTEndian_SwapBE64(n)    (n)
     #define SkTEndian_SwapLE16(n)    SkTEndianSwap16<n>::value
     #define SkTEndian_SwapLE32(n)    SkTEndianSwap32<n>::value
