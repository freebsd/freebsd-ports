--- ieee-utils/fp-freebsd.c.orig	2014-02-03 11:46:44.000000000 -0600
+++ ieee-utils/fp-freebsd.c	2014-02-03 11:46:18.000000000 -0600
@@ -24,10 +24,28 @@
 int
 gsl_ieee_set_mode (int precision, int rounding, int exception_mask)
 {
-  fp_prec_t prec = 0 ;
   fp_except_t mode = 0 ;
   fp_rnd_t    rnd  = 0 ;
 
+#ifdef __powerpc__
+  switch (precision)
+    {
+    case GSL_IEEE_SINGLE_PRECISION:
+      GSL_ERROR ("powerpc only supports default precision rounding", GSL_EUNSUP)
+;
+      break ;
+    case GSL_IEEE_DOUBLE_PRECISION:
+      GSL_ERROR ("powerpc only supports default precision rounding", GSL_EUNSUP)
+;
+      break ;
+    case GSL_IEEE_EXTENDED_PRECISION:
+      GSL_ERROR ("powerpc only supports default precision rounding", GSL_EUNSUP)
+;
+      break ;
+    }
+#else
+  fp_prec_t prec = 0 ;
+
   switch (precision)
     {
     case GSL_IEEE_SINGLE_PRECISION:
@@ -43,6 +61,7 @@
       fpsetprec(prec);
       break ;
     }
+#endif
 
   switch (rounding)
     {
@@ -69,13 +88,23 @@
 
   /* Turn on all the exceptions apart from 'inexact' */
 
-  mode = FP_X_INV | FP_X_DNML | FP_X_DZ | FP_X_OFL | FP_X_UFL ;
+  mode = FP_X_INV | FP_X_DZ | FP_X_OFL | FP_X_UFL ;
 
   if (exception_mask & GSL_IEEE_MASK_INVALID)
     mode &= ~ FP_X_INV ;
 
   if (exception_mask & GSL_IEEE_MASK_DENORMALIZED)
-    mode &= ~ FP_X_DNML ;
+    {
+      /* do nothing */
+    }
+  else
+    {
+#ifdef __powerpc__
+      GSL_ERROR ("powerpc does not support the denormalized operand exception. "                 "Use 'mask-denormalized' to work around this.", GSL_EUNSUP) ;
+#else
+      mode |= FP_X_DNML;
+#endif
+    }
 
   if (exception_mask & GSL_IEEE_MASK_DIVISION_BY_ZERO)
     mode &= ~ FP_X_DZ ;
