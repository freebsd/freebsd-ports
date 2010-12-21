--- mlpy/cwt/cwb.c.orig	2010-12-21 09:10:04.000000000 +0800
+++ mlpy/cwt/cwb.c	2010-12-21 09:12:05.000000000 +0800
@@ -142,9 +142,12 @@
   complex double p = 0.0 + 0.0I; 
   double sw, norm = 1.0;
   
-  
+#ifndef __STD_IEC_559_COMPLEX__  /* FreeBSD lacks C99 cpow() */
+  p = - gsl_complex_pow(0.0 + 1.0I, order) / sqrt(gsl_sf_gamma(order + 0.5));
+#else
   p = - cpow(0.0 + 1.0I, order) / sqrt(gsl_sf_gamma(order + 0.5));
-  
+#endif /* __STD_IEC_559_COMPLEX__ */
+
   for (i=0; i<n; i++)
     {
       if (nm == 1)
