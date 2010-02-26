--- ./src/modules/xine/yadif.c.orig	2010-02-16 07:40:46.000000000 +0100
+++ ./src/modules/xine/yadif.c	2010-02-25 23:10:51.289144010 +0100
@@ -34,7 +34,8 @@
 
 static void (*filter_line)(int mode, uint8_t *dst, const uint8_t *prev, const uint8_t *cur, const uint8_t *next, int w, int refs, int parity);
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && defined(USE_SSE)
+
 #define LOAD4(mem,dst) \
             "movd      "mem", "#dst" \n\t"\
             "punpcklbw %%mm7, "#dst" \n\t"
@@ -264,6 +265,7 @@
 #endif
 
 // ================= SSE2 =================
+#ifdef USE_SSE2
 #define PABS(tmp,dst) \
             "pxor     "#tmp", "#tmp" \n\t"\
             "psubw    "#dst", "#tmp" \n\t"\
@@ -271,17 +273,19 @@
 
 #define FILTER_LINE_FUNC_NAME filter_line_sse2
 #include "vf_yadif_template.h"
+#endif
 
 // ================ SSSE3 =================
+#ifdef USE_SSE3
 #define PABS(tmp,dst) \
             "pabsw     "#dst", "#dst" \n\t"
 
 #define FILTER_LINE_FUNC_NAME filter_line_ssse3
 #include "vf_yadif_template.h"
-
 #endif
 
-#endif
+#endif // GCC 4.2+
+#endif // GNUC, USE_SSE
 
 static void filter_line_c(int mode, uint8_t *dst, const uint8_t *prev, const uint8_t *cur, const uint8_t *next, int w, int refs, int parity){
     int x;
@@ -356,15 +360,22 @@
 	filter_line = filter_line_c;
 #ifdef __GNUC__
 #if (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__>1)
+#ifdef USE_SSE3
 	if (cpu & AVS_CPU_SSSE3)
 		filter_line = filter_line_ssse3;
-	else if (cpu & AVS_CPU_SSE2)
+	else
+#endif
+#ifdef USE_SSE2
+	if (cpu & AVS_CPU_SSE2)
 		filter_line = filter_line_sse2;
 	else
 #endif
+#endif // GCC 4.2+
+#ifdef USE_SSE
 	if (cpu & AVS_CPU_INTEGER_SSE)
 		filter_line = filter_line_mmx2;
 #endif
+#endif // GNUC
         y=0;
         if(((y ^ parity) & 1)){
             memcpy(dst, cur0 + refs, w);// duplicate 1
@@ -401,14 +412,13 @@
             memcpy(dst + (h-1)*dst_stride, cur0 + (h-1)*refs, w); // copy original
         }
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && defined(USE_SSE)
 	if (cpu >= AVS_CPU_INTEGER_SSE)
 		asm volatile("emms");
 #endif
 }
 
-#ifdef __GNUC__
-#ifndef PIC
+#if defined(__GNUC__) && defined(USE_SSE) && !defined(PIC)
 static attribute_align_arg void  YUY2ToPlanes_mmx(const unsigned char *srcYUY2, int pitch_yuy2, int width, int height,
                     unsigned char *py, int pitch_y,
                     unsigned char *pu, unsigned char *pv,  int pitch_uv)
@@ -486,8 +496,7 @@
     }
     asm ("sfence \n\t emms");
 }
-#endif
-#endif
+#endif // GNUC, USE_SSE, !PIC
 
 //----------------------------------------------------------------------------------------------
 
@@ -498,7 +507,7 @@
 
     int h,w;
     int w0 = 0;
-#if defined(__GNUC__) && !defined(PIC)
+#if defined(__GNUC__) && defined(USE_SSE) && !defined(PIC)
     if (cpu & AVS_CPU_INTEGER_SSE) {
         w0 = (nWidth/8)*8;
         YUY2ToPlanes_mmx(pSrcYUY2, nSrcPitchYUY2, w0, nHeight, pSrcY, srcPitchY, pSrcU, pSrcV, srcPitchUV);
@@ -529,7 +538,7 @@
 {
     int h,w;
     int w0 = 0;
-#if defined(__GNUC__) && !defined(PIC)
+#if defined(__GNUC__) && defined(USE_SSE) && !defined(PIC)
     if (cpu & AVS_CPU_INTEGER_SSE) {
         w0 = (nWidth/8)*8;
         YUY2FromPlanes_mmx(pSrcYUY2, nSrcPitchYUY2, w0, nHeight, pSrcY, srcPitchY, pSrcU, pSrcV, srcPitchUV);
