--- gsl/gsl_sf.ml.orig	2014-04-12 01:43:31 UTC
+++ gsl/gsl_sf.ml
@@ -1142,6 +1142,7 @@ external legendre_Ql_e : int -> float -> result
 
 
 
+(*
 (* Associated LEGENDRE functions *)
 external legendre_Plm : int -> int -> float -> float
     = "ml_gsl_sf_legendre_Plm"
@@ -1167,6 +1168,7 @@ external  legendre_sphPlm_array : int -> int -> float 
 
 external  legendre_array_size : int -> int -> int 
     = "ml_gsl_sf_legendre_array_size"
+*)
 
 
 
