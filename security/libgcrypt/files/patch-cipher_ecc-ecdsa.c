--- cipher/ecc-ecdsa.c.orig	2025-09-23 13:14:22 UTC
+++ cipher/ecc-ecdsa.c
@@ -89,7 +89,7 @@ _gcry_ecc_ecdsa_sign (gcry_mpi_t input, gcry_mpi_t k_s
   sum = mpi_alloc (0);
   k_1 = mpi_alloc (0);
   x = mpi_alloc (0);
-  point_init (&I);
+  point_init (&I, ec->nbits);
 
   /* Two loops to avoid R or S are zero.  This is more of a joke than
      a real demand because the probability of them being zero is less
@@ -268,9 +268,9 @@ _gcry_ecc_ecdsa_verify (gcry_mpi_t input, mpi_ec_t ec,
   h1 = mpi_alloc (0);
   h2 = mpi_alloc (0);
   x = mpi_alloc (0);
-  point_init (&Q);
-  point_init (&Q1);
-  point_init (&Q2);
+  point_init (&Q, ec->nbits);
+  point_init (&Q1, ec->nbits);
+  point_init (&Q2, ec->nbits);
 
   /* h  = s^(-1) (mod n) */
   mpi_invm (h, s, ec->n);
