--- src/3rdparty/chromium/third_party/skia/src/opts/Sk4px_none.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/Sk4px_none.h
@@ -35,7 +35,6 @@ inline Sk4px Sk4px::Wide::div255() const {
 }
 
 inline Sk4px Sk4px::alphas() const {
-    static_assert(SK_A32_SHIFT == 24, "This method assumes little-endian.");
     return Sk16b((*this)[ 3], (*this)[ 3], (*this)[ 3], (*this)[ 3],
                  (*this)[ 7], (*this)[ 7], (*this)[ 7], (*this)[ 7],
                  (*this)[11], (*this)[11], (*this)[11], (*this)[11],
