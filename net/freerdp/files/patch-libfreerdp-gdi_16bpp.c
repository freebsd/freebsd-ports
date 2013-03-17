diff --git a/libfreerdp-gdi/16bpp.c b/libfreerdp-gdi/16bpp.c
index 22b0009..46ca0df 100644
--- libfreerdp-gdi/16bpp.c
+++ libfreerdp-gdi/16bpp.c
@@ -878,96 +878,96 @@ int PatBlt_16bpp(HGDI_DC hdc, int nXLeft, int nYLeft, int nWidth, int nHeight, i
 	return 1;
 }
 
-INLINE void SetPixel_BLACK_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_BLACK_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = 0 */
 	*pixel = 0;
 }
 
-INLINE void SetPixel_NOTMERGEPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOTMERGEPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = ~(D | P) */
 	*pixel = ~(*pixel | *pen);
 }
 
-INLINE void SetPixel_MASKNOTPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MASKNOTPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = D & ~P */
 	*pixel &= ~(*pen);
 }
 
-INLINE void SetPixel_NOTCOPYPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOTCOPYPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = ~P */
 	*pixel = ~(*pen);
 }
 
-INLINE void SetPixel_MASKPENNOT_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MASKPENNOT_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = P & ~D */
 	*pixel = *pen & ~*pixel;
 }
 
-INLINE void SetPixel_NOT_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOT_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = ~D */
 	*pixel = ~(*pixel);
 }
 
-INLINE void SetPixel_XORPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_XORPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = D ^ P */
 	*pixel = *pixel ^ *pen;
 }
 
-INLINE void SetPixel_NOTMASKPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOTMASKPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = ~(D & P) */
 	*pixel = ~(*pixel & *pen);
 }
 
-INLINE void SetPixel_MASKPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MASKPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = D & P */
 	*pixel &= *pen;
 }
 
-INLINE void SetPixel_NOTXORPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOTXORPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = ~(D ^ P) */
 	*pixel = ~(*pixel ^ *pen);
 }
 
-INLINE void SetPixel_NOP_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_NOP_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = D */
 }
 
-INLINE void SetPixel_MERGENOTPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MERGENOTPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = D | ~P */
 	*pixel |= ~(*pen);
 }
 
-INLINE void SetPixel_COPYPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_COPYPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = P */
 	*pixel = *pen;
 }
 
-INLINE void SetPixel_MERGEPENNOT_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MERGEPENNOT_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = P | ~D */
 	*pixel = *pen | ~(*pixel);
 }
 
-INLINE void SetPixel_MERGEPEN_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_MERGEPEN_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = P | D */
 	*pixel |= *pen;
 }
 
-INLINE void SetPixel_WHITE_16bpp(uint16 *pixel, uint16 *pen)
+static INLINE void SetPixel_WHITE_16bpp(uint16 *pixel, uint16 *pen)
 {
 	/* D = 1 */
 	*pixel = 0xFFFF;
