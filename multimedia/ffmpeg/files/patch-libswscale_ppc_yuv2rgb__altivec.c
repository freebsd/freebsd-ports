Error:
libswscale/ppc/yuv2rgb_altivec.c:288:36: error: redeclaration of 'vec_xl' must have the 'overloadable' attribute
static inline vector unsigned char vec_xl(signed long long offset, const ubyte *addr)

--- libswscale/ppc/yuv2rgb_altivec.c.orig	2021-04-08 21:28:40 UTC
+++ libswscale/ppc/yuv2rgb_altivec.c
@@ -284,7 +284,7 @@ static inline void cvtyuvtoRGB(SwsContext *c, vector s
  * ------------------------------------------------------------------------------
  */
 
-#if !HAVE_VSX
+#if !HAVE_VSX && !defined(__clang__)
 static inline vector unsigned char vec_xl(signed long long offset, const ubyte *addr)
 {
     const vector unsigned char *v_addr = (const vector unsigned char *) (addr + offset);
