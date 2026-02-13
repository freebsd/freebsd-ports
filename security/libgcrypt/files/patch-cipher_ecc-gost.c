--- cipher/ecc-gost.c.orig	2021-02-12 11:23:24 UTC
+++ cipher/ecc-gost.c
@@ -63,7 +63,7 @@ _gcry_ecc_gost_sign (gcry_mpi_t input, mpi_ec_t ec,
   ke = mpi_alloc (0);
   e = mpi_alloc (0);
   x = mpi_alloc (0);
-  point_init (&I);
+  point_init (&I, ec->nbits);
 
   mpi_mod (e, input, ec->n); /* e = hash mod n */
 
@@ -148,9 +148,9 @@ _gcry_ecc_gost_verify (gcry_mpi_t input, mpi_ec_t ec,
   rv = mpi_alloc (0);
   zero = mpi_alloc (0);
 
-  point_init (&Q);
-  point_init (&Q1);
-  point_init (&Q2);
+  point_init (&Q, ec->nbits);
+  point_init (&Q1, ec->nbits);
+  point_init (&Q2, ec->nbits);
 
   mpi_mod (e, input, ec->n); /* e = hash mod n */
   if (!mpi_cmp_ui (e, 0))
