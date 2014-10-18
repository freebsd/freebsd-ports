--- src/post/planar/eq2.c.orig
+++ src/post/planar/eq2.c
@@ -129,7 +129,7 @@ void affine_1d_MMX (eq2_param_t *par, un
     "movq (%1), %%mm4 \n\t"
     "pxor %%mm0, %%mm0 \n\t"
     :
-    : "g" (brvec), "g" (contvec)
+    : "r" (brvec), "r" (contvec)
   );
 
   while (h-- > 0) {
