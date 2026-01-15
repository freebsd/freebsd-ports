--- external/FFmpeg/libswscale/ppc/yuv2rgb_altivec.c.orig	2025-02-24 16:35:12 UTC
+++ external/FFmpeg/libswscale/ppc/yuv2rgb_altivec.c
@@ -316,6 +316,9 @@ static int altivec_ ## name(SwsContext *c, const unsig
     vector signed short R1, G1, B1;                                           \
     vector unsigned char R, G, B;                                             \
                                                                               \
+    const vector unsigned char *y1ivP, *y2ivP, *uivP, *vivP;                  \
+    vector unsigned char align_perm;                                          \
+                                                                              \
     vector signed short lCY       = c->CY;                                    \
     vector signed short lOY       = c->OY;                                    \
     vector signed short lCRV      = c->CRV;                                   \
@@ -346,13 +349,26 @@ static int altivec_ ## name(SwsContext *c, const unsig
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
