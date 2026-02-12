--- formulas.h.orig	2001-04-09 13:00:19 UTC
+++ formulas.h
@@ -50,7 +50,7 @@ struct formula {
 #define FORMULAMAGIC 1121
 struct formula {
     int magic;
-    int (*calculate) (number_t, number_t, number_t, number_t) REGISTERS(3);
+    int (*calculate) (number_t, number_t, number_t, number_t);
     char *name[2];
     vinfo v;
     int mandelbrot;
