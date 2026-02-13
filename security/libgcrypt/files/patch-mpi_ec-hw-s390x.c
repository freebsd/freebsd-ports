--- mpi/ec-hw-s390x.c.orig	2022-01-25 21:55:44 UTC
+++ mpi/ec-hw-s390x.c
@@ -242,8 +242,8 @@ _gcry_s390x_ec_hw_mul_point (mpi_point_t result, gcry_
   if (!(pcc_query () & km_function_to_mask (pcc_func)))
     return -1; /* HW does not support acceleration for this curve. */
 
-  x = mpi_new (0);
-  y = mpi_new (0);
+  x = mpi_new (ctx->nbits);
+  y = mpi_new (ctx->nbits);
 
   if (_gcry_mpi_ec_get_affine (x, y, point, ctx) < 0)
     {
@@ -352,7 +352,7 @@ s390_mul_point_montgomery (mpi_point_t result, gcry_mp
   if (!(pcc_query () & km_function_to_mask (pcc_func)))
     return -1; /* HW does not support acceleration for this curve. */
 
-  x = mpi_new (0);
+  x = mpi_new (ctx->nbits);
 
   if (mpi_is_opaque (scalar))
     {
