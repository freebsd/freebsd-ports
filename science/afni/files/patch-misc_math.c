--- misc_math.c.orig	2015-11-06 21:25:08 UTC
+++ misc_math.c
@@ -1,6 +1,13 @@
 
+/* For older libm */
+double log2(double n)
+{
+    return log(n) / log(2.0);
+}
+
 /* move from Deconvolve.c into libmri.a         21 Jun 2010 [rickr] */
 
+
 double legendre( double x , int m )   /* Legendre polynomials over [-1,1] */
 {
    if( m < 0 ) return 1.0 ;    /* bad input */
