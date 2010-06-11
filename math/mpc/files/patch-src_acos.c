--- src/acos.c.orig	2010-06-11 16:14:09.000000000 +0200
+++ src/acos.c	2010-06-11 16:14:30.000000000 +0200
@@ -189,7 +189,7 @@
     rnd_im = rnd_im == GMP_RNDU ? GMP_RNDD
       : rnd_im == GMP_RNDD ? GMP_RNDU
 #if MPFR_VERSION_MAJOR >= 3
-      : rnd_im == GMP_RNDA ? GMP_RNDZ
+      : rnd_im == MPFR_RNDA ? MPFR_RNDZ
 #endif
       : rnd_im;
   rnd1 = RNDC(GMP_RNDN, rnd_im);
