diff --git a/libfreerdp-gdi/8bpp.c b/libfreerdp-gdi/8bpp.c
index e10dde4..bddf327 100644
--- libfreerdp-gdi/8bpp.c
+++ libfreerdp-gdi/8bpp.c
@@ -793,96 +793,96 @@ int PatBlt_8bpp(HGDI_DC hdc, int nXLeft, int nYLeft, int nWidth, int nHeight, in
 	return 1;
 }
 
-INLINE void SetPixel_BLACK_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_BLACK_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = 0 */
 	*pixel = 0;
 }
 
-INLINE void SetPixel_NOTMERGEPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOTMERGEPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = ~(D | P) */
 	*pixel = ~(*pixel | *pen);
 }
 
-INLINE void SetPixel_MASKNOTPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MASKNOTPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = D & ~P */
 	*pixel &= ~(*pen);
 }
 
-INLINE void SetPixel_NOTCOPYPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOTCOPYPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = ~P */
 	*pixel = ~(*pen);
 }
 
-INLINE void SetPixel_MASKPENNOT_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MASKPENNOT_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = P & ~D */
 	*pixel = *pen & ~*pixel;
 }
 
-INLINE void SetPixel_NOT_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOT_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = ~D */
 	*pixel = ~(*pixel);
 }
 
-INLINE void SetPixel_XORPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_XORPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = D ^ P */
 	*pixel = *pixel ^ *pen;
 }
 
-INLINE void SetPixel_NOTMASKPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOTMASKPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = ~(D & P) */
 	*pixel = ~(*pixel & *pen);
 }
 
-INLINE void SetPixel_MASKPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MASKPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = D & P */
 	*pixel &= *pen;
 }
 
-INLINE void SetPixel_NOTXORPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOTXORPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = ~(D ^ P) */
 	*pixel = ~(*pixel ^ *pen);
 }
 
-INLINE void SetPixel_NOP_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_NOP_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = D */
 }
 
-INLINE void SetPixel_MERGENOTPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MERGENOTPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = D | ~P */
 	*pixel |= ~(*pen);
 }
 
-INLINE void SetPixel_COPYPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_COPYPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = P */
 	*pixel = *pen;
 }
 
-INLINE void SetPixel_MERGEPENNOT_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MERGEPENNOT_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = P | ~D */
 	*pixel = *pen | ~(*pixel);
 }
 
-INLINE void SetPixel_MERGEPEN_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_MERGEPEN_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = P | D */
 	*pixel |= *pen;
 }
 
-INLINE void SetPixel_WHITE_8bpp(uint8* pixel, uint8* pen)
+static INLINE void SetPixel_WHITE_8bpp(uint8* pixel, uint8* pen)
 {
 	/* D = 1 */
 	*pixel = 0xFF;
