Obtained from:
https://sources.debian.net/src/orpie/1.5.2-1/debian/patches/gsl-fix/

Description: fix some incompatibilities with libgsl 2.1
Author: Uwe Steinmann <steinm@debian.org>
Forwarded: not-needed

--- gsl/mlgsl_sf.c.orig	2014-04-12 01:43:31 UTC
+++ gsl/mlgsl_sf.c
@@ -258,7 +258,8 @@ SF2(ellint_Dcomp, Double_val, GSL_MODE_v
 SF3(ellint_F, Double_val, Double_val, GSL_MODE_val)
 SF3(ellint_E, Double_val, Double_val, GSL_MODE_val)
 SF4(ellint_P, Double_val, Double_val, Double_val, GSL_MODE_val)
-SF4(ellint_D, Double_val, Double_val, Double_val, GSL_MODE_val)
+//SF4(ellint_D, Double_val, Double_val, Double_val, GSL_MODE_val)
+SF3(ellint_D, Double_val, Double_val, GSL_MODE_val)
 SF3(ellint_RC, Double_val, Double_val, GSL_MODE_val)
 SF4(ellint_RD, Double_val, Double_val, Double_val, GSL_MODE_val)
 SF4(ellint_RF, Double_val, Double_val, Double_val, GSL_MODE_val)
@@ -452,6 +453,7 @@ SF1(legendre_Q1, Double_val)
 SF2(legendre_Ql, Int_val, Double_val)
 
 /* Associated Legendre Polynomials and Spherical Harmonics  */
+/*
 SF3(legendre_Plm, Int_val, Int_val, Double_val) 
 CAMLprim value 
 ml_gsl_sf_legendre_Plm_array(value lmax, value m, value x, value result_array)
@@ -487,7 +489,7 @@ ml_gsl_sf_legendre_array_size(value lmax
   ret = Val_int(gsl_ret);
   CAMLreturn(ret);
 }
-
+*/
 /* LOGARITHM and related functions */
 SF1(log, Double_val)
 SF1(log_abs, Double_val)
