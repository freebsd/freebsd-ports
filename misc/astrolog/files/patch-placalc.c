--- placalc.c.orig	2011-05-11 16:19:54.000000000 +0000
+++ placalc.c	2011-05-11 16:20:31.000000000 +0000
@@ -900,7 +900,7 @@
   static double last_j0_outer = HUGE8;
   static double last_j0_chiron = HUGE8;
   static double last_j0_aster = HUGE8;
-  static long icoord[6][5][3], chicoord[6][3], ascoord[6][4][3];
+  static word4 icoord[6][5][3], chicoord[6][3], ascoord[6][4][3];
   REAL8 j0, jd, jfrac;
   REAL8 l[6], r[6], z[6];
   int n, order, p;
