--- sage-5.0.beta13/sage/combinat/partitions_c.cc-orig	2012-04-20 01:01:41.000000000 +0000
+++ sage-5.0/sage/combinat/partitions_c.cc	2012-04-20 01:02:47.000000000 +0000
@@ -152,7 +152,7 @@
 const unsigned int double_precision = DBL_MANT_DIG;                         // The assumed precision of a double.
 
 
-#if defined(__sparc) || defined(__CYGWIN__)
+#if defined(__sparc) || defined(__CYGWIN__) || defined(__FreeBSD__)
 // On sparc solaris long double is bad/broken/different, etc.  E.g.,
 // LDBL_MANT_DIG is 113 rather than 106, which causes all kinds of trouble.
 // So we only use double_precision.
