--- cipher/ecc-misc.c.orig	2025-03-13 09:47:17 UTC
+++ cipher/ecc-misc.c
@@ -60,7 +60,7 @@ _gcry_ecc_curve_copy (elliptic_curve_t E)
   R.p = mpi_copy (E.p);
   R.a = mpi_copy (E.a);
   R.b = mpi_copy (E.b);
-  _gcry_mpi_point_init (&R.G);
+  _gcry_mpi_point_init (&R.G, 0);
   point_set (&R.G, &E.G);
   R.n = mpi_copy (E.n);
   R.h = E.h;
@@ -159,8 +159,8 @@ _gcry_mpi_ec_ec2os (gcry_mpi_point_t point, mpi_ec_t e
 {
   gcry_mpi_t g_x, g_y, result;
 
-  g_x = mpi_new (0);
-  g_y = mpi_new (0);
+  g_x = mpi_new (ec->nbits);
+  g_y = mpi_new (ec->nbits);
   if (_gcry_mpi_ec_get_affine (g_x, g_y, point, ec))
     result = NULL;
   else
@@ -236,10 +236,10 @@ _gcry_ecc_sec_decodepoint  (gcry_mpi_t value, mpi_ec_t
        * Recover Y.  The Weierstrass curve: y^2 = x^3 + a*x + b
        */
 
-      x3 = mpi_new (0);
-      t = mpi_new (0);
-      p1_4 = mpi_new (0);
-      y = mpi_new (0);
+      x3 = mpi_new (ec->nbits);
+      t = mpi_new (ec->nbits);
+      p1_4 = mpi_new (ec->nbits);
+      y = mpi_new (ec->nbits);
 
       /* Compute right hand side.  */
       mpi_powm (x3, x, mpi_const (MPI_C_THREE), ec->p);
