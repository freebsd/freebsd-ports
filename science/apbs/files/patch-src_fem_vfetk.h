-- Match Vfetk_PDE_u_T prototype to the FETK mc PDE struct used in the
-- bundled FETK source, which passes an additional dF[][3] gradient argument.
--- src/fem/vfetk.h.orig	2022-04-29 11:53:08.000000000 -0700
+++ src/fem/vfetk.h	2026-09-26 18:39:56.629492000 -0700
@@ -751,7 +751,8 @@
         int type, /**< Point type */
         int chart, /**< Chart for point coordinates */
         double txq[], /**< Point coordinates */
-        double F[] /**< Set to value at point */
+        double F[], /**< Set to value at point */
+        double dF[][3] /**< Set to gradient at point (unused) */
         );

 /**
