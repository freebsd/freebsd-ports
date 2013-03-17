diff --git a/libfreerdp-gdi/32bpp.c b/libfreerdp-gdi/32bpp.c
index 8ed8553..0d5fbd2 100644
--- libfreerdp-gdi/32bpp.c
+++ libfreerdp-gdi/32bpp.c
@@ -920,96 +920,96 @@ int PatBlt_32bpp(HGDI_DC hdc, int nXLeft, int nYLeft, int nWidth, int nHeight, i
 	return 1;
 }
 
-INLINE void SetPixel_BLACK_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_BLACK_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = 0 */
 	*pixel = 0;
 }
 
-INLINE void SetPixel_NOTMERGEPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOTMERGEPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = ~(D | P) */
 	*pixel = ~(*pixel | *pen);
 }
 
-INLINE void SetPixel_MASKNOTPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MASKNOTPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = D & ~P */
 	*pixel &= ~(*pen);
 }
 
-INLINE void SetPixel_NOTCOPYPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOTCOPYPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = ~P */
 	*pixel = ~(*pen);
 }
 
-INLINE void SetPixel_MASKPENNOT_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MASKPENNOT_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = P & ~D */
 	*pixel = *pen & ~*pixel;
 }
 
-INLINE void SetPixel_NOT_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOT_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = ~D */
 	*pixel = ~(*pixel);
 }
 
-INLINE void SetPixel_XORPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_XORPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = D ^ P */
 	*pixel = *pixel ^ *pen;
 }
 
-INLINE void SetPixel_NOTMASKPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOTMASKPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = ~(D & P) */
 	*pixel = ~(*pixel & *pen);
 }
 
-INLINE void SetPixel_MASKPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MASKPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = D & P */
 	*pixel &= *pen;
 }
 
-INLINE void SetPixel_NOTXORPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOTXORPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = ~(D ^ P) */
 	*pixel = ~(*pixel ^ *pen);
 }
 
-INLINE void SetPixel_NOP_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_NOP_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = D */
 }
 
-INLINE void SetPixel_MERGENOTPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MERGENOTPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = D | ~P */
 	*pixel |= ~(*pen);
 }
 
-INLINE void SetPixel_COPYPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_COPYPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = P */
 	*pixel = *pen;
 }
 
-INLINE void SetPixel_MERGEPENNOT_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MERGEPENNOT_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = P | ~D */
 	*pixel = *pen | ~(*pixel);
 }
 
-INLINE void SetPixel_MERGEPEN_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_MERGEPEN_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = P | D */
 	*pixel |= *pen;
 }
 
-INLINE void SetPixel_WHITE_32bpp(uint32* pixel, uint32* pen)
+static INLINE void SetPixel_WHITE_32bpp(uint32* pixel, uint32* pen)
 {
 	/* D = 1 */
 	*pixel = 0xFFFFFF;
