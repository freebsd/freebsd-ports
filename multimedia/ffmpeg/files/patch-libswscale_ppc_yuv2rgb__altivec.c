Revert 3a557c5d88b7b15b5954ba2743febb055549b536 to fix build on powerpc and powerpc64.

Error:
CC	libswscale/ppc/yuv2rgb_altivec.o
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_abgr?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: implicit declaration of function ?vec_xl?; did you mean ?vec_rl?? [-Werror=implicit-function-declaration]
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:437:1: note: in expansion of macro ?DEFCSP420_CVT?
  437 | DEFCSP420_CVT(yuv2_abgr,  out_abgr)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:437:1: note: in expansion of macro ?DEFCSP420_CVT?
  437 | DEFCSP420_CVT(yuv2_abgr,  out_abgr)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:437:1: note: in expansion of macro ?DEFCSP420_CVT?
  437 | DEFCSP420_CVT(yuv2_abgr,  out_abgr)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:437:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:437:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_bgra?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:438:1: note: in expansion of macro ?DEFCSP420_CVT?
  438 | DEFCSP420_CVT(yuv2_bgra,  out_bgra)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:438:1: note: in expansion of macro ?DEFCSP420_CVT?
  438 | DEFCSP420_CVT(yuv2_bgra,  out_bgra)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:438:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:438:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_rgba?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:439:1: note: in expansion of macro ?DEFCSP420_CVT?
  439 | DEFCSP420_CVT(yuv2_rgba,  out_rgba)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:439:1: note: in expansion of macro ?DEFCSP420_CVT?
  439 | DEFCSP420_CVT(yuv2_rgba,  out_rgba)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:439:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:439:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_argb?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:440:1: note: in expansion of macro ?DEFCSP420_CVT?
  440 | DEFCSP420_CVT(yuv2_argb,  out_argb)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:440:1: note: in expansion of macro ?DEFCSP420_CVT?
  440 | DEFCSP420_CVT(yuv2_argb,  out_argb)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:440:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:440:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_rgb24?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:441:1: note: in expansion of macro ?DEFCSP420_CVT?
  441 | DEFCSP420_CVT(yuv2_rgb24, out_rgb24)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:441:1: note: in expansion of macro ?DEFCSP420_CVT?
  441 | DEFCSP420_CVT(yuv2_rgb24, out_rgb24)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:441:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:441:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c: In function ?altivec_yuv2_bgr24?:
libswscale/ppc/yuv2rgb_altivec.c:338:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  338 |             y0 = vec_xl(0, y1i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:442:1: note: in expansion of macro ?DEFCSP420_CVT?
  442 | DEFCSP420_CVT(yuv2_bgr24, out_bgr24)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:340:18: error: incompatible types when assigning to type ?__vector unsigned char? {aka ?__vector(16) unsigned char?} from type ?int?
  340 |             y1 = vec_xl(0, y2i);                                              \
      |                  ^~~~~~
libswscale/ppc/yuv2rgb_altivec.c:442:1: note: in expansion of macro ?DEFCSP420_CVT?
  442 | DEFCSP420_CVT(yuv2_bgr24, out_bgr24)
      | ^~~~~~~~~~~~~
libswscale/ppc/yuv2rgb_altivec.c:442:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
libswscale/ppc/yuv2rgb_altivec.c:442:1: error: can?t convert a value of type ?int? to vector type ?__vector(16) signed char? which has different size
cc1: some warnings being treated as errors

--- libswscale/ppc/yuv2rgb_altivec.c.orig	2020-06-15 18:54:24 UTC
+++ libswscale/ppc/yuv2rgb_altivec.c
@@ -305,6 +305,9 @@ static int altivec_ ## name(SwsContext *c, const unsig
     vector signed short R1, G1, B1;                                           \
     vector unsigned char R, G, B;                                             \
                                                                               \
+    const vector unsigned char *y1ivP, *y2ivP, *uivP, *vivP;                  \
+    vector unsigned char align_perm;                                          \
+                                                                              \
     vector signed short lCY       = c->CY;                                    \
     vector signed short lOY       = c->OY;                                    \
     vector signed short lCRV      = c->CRV;                                   \
@@ -335,13 +338,26 @@ static int altivec_ ## name(SwsContext *c, const unsig
         vec_dstst(oute, (0x02000002 | (((w * 3 + 32) / 32) << 16)), 1);       \
                                                                               \
         for (j = 0; j < w / 16; j++) {                                        \
-            y0 = vec_xl(0, y1i);                                              \
+            y1ivP = (const vector unsigned char *) y1i;                       \
+            y2ivP = (const vector unsigned char *) y2i;                       \
+            uivP  = (const vector unsigned char *) ui;                        \
+            vivP  = (const vector unsigned char *) vi;                        \
                                                                               \
-            y1 = vec_xl(0, y2i);                                              \
+            align_perm = vec_lvsl(0, y1i);                                    \
+            y0 = (vector unsigned char)                                       \
+                     vec_perm(y1ivP[0], y1ivP[1], align_perm);                \
                                                                               \
-            u = (vector signed char) vec_xl(0, ui);                           \
+            align_perm = vec_lvsl(0, y2i);                                    \
+            y1 = (vector unsigned char)                                       \
+                     vec_perm(y2ivP[0], y2ivP[1], align_perm);                \
                                                                               \
-            v = (vector signed char) vec_xl(0, vi);                           \
+            align_perm = vec_lvsl(0, ui);                                     \
+            u = (vector signed char)                                          \
+                    vec_perm(uivP[0], uivP[1], align_perm);                   \
+                                                                              \
+            align_perm = vec_lvsl(0, vi);                                     \
+            v = (vector signed char)                                          \
+                    vec_perm(vivP[0], vivP[1], align_perm);                   \
                                                                               \
             u = (vector signed char)                                          \
                     vec_sub(u,                                                \
