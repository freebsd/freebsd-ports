--- common/rfb/ZRLEDecoder.cxx.orig	2024-07-23 08:50:25 UTC
+++ common/rfb/ZRLEDecoder.cxx
@@ -126,10 +126,10 @@ void ZRLEDecoder::zrleDecode(const Rect& r, rdr::InStr
   Pixel maxPixel = pf.pixelFromRGB((uint16_t)-1, (uint16_t)-1, (uint16_t)-1);
   bool fitsInLS3Bytes = maxPixel < (1<<24);
   bool fitsInMS3Bytes = (maxPixel & 0xff) == 0;
-  bool isLowCPixel = (sizeof(T) == 4) &&
+  bool isLowCPixel = (sizeof(T) == 4) && (pf.depth <= 24) &&
                      ((fitsInLS3Bytes && pf.isLittleEndian()) ||
                       (fitsInMS3Bytes && pf.isBigEndian()));
-  bool isHighCPixel = (sizeof(T) == 4) &&
+  bool isHighCPixel = (sizeof(T) == 4) && (pf.depth <= 24) &&
                       ((fitsInLS3Bytes && pf.isBigEndian()) ||
                        (fitsInMS3Bytes && pf.isLittleEndian()));
 
