--- external/FFmpeg/libswscale/ppc/yuv2rgb_altivec.c.orig	2022-09-13 01:58:14 UTC
+++ external/FFmpeg/libswscale/ppc/yuv2rgb_altivec.c
@@ -284,7 +284,7 @@ static inline void cvtyuvtoRGB(SwsContext *c, vector s
  * ------------------------------------------------------------------------------
  */
 
-#if !HAVE_VSX
+#if !HAVE_VSX && !defined(__clang__)
 static inline vector unsigned char vec_xl(signed long long offset, const ubyte *addr)
 {
     const vector unsigned char *v_addr = (const vector unsigned char *) (addr + offset);
