--- misc_math.c.orig	2010-06-22 08:15:42.000000000 -0500
+++ misc_math.c	2013-10-29 20:59:28.000000000 -0500
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
