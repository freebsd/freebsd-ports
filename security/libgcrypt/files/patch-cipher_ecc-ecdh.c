--- cipher/ecc-ecdh.c.orig	2025-05-08 06:47:34 UTC
+++ cipher/ecc-ecdh.c
@@ -131,7 +131,7 @@ _gcry_ecc_curve_keypair (const char *curve,
     return GPG_ERR_UNKNOWN_CURVE;
 
   x = mpi_new (nbits);
-  point_init (&Q);
+  point_init (&Q, ec->nbits);
 
   _gcry_mpi_ec_mul_point (&Q, mpi_k, ec->G, ec);
 
@@ -254,14 +254,14 @@ _gcry_ecc_curve_mul_point (const char *curve,
       goto leave;
     }
 
-  point_init (&Q);
+  point_init (&Q, ec->nbits);
 
   if (point)
     {
       gcry_mpi_t mpi_u = _gcry_mpi_set_opaque_copy (NULL, point, point_len*8);
       mpi_point_struct P;
 
-      point_init (&P);
+      point_init (&P, ec->nbits);
       if (ec->model == MPI_EC_WEIERSTRASS)
         err = _gcry_ecc_sec_decodepoint (mpi_u, ec, &P);
       else /* MPI_EC_MONTGOMERY */
