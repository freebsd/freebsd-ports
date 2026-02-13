--- cipher/ecc-eddsa.c.orig	2025-07-14 12:48:50 UTC
+++ cipher/ecc-eddsa.c
@@ -126,8 +126,8 @@ _gcry_ecc_eddsa_encodepoint (mpi_point_t point, mpi_ec
   gpg_err_code_t rc;
   gcry_mpi_t x, y;
 
-  x = x_in? x_in : mpi_new (0);
-  y = y_in? y_in : mpi_new (0);
+  x = x_in? x_in : mpi_new (ec->nbits);
+  y = y_in? y_in : mpi_new (ec->nbits);
 
   if (_gcry_mpi_ec_get_affine (x, y, point, ec))
     {
@@ -219,11 +219,11 @@ ecc_ed448_recover_x (gcry_mpi_t x, gcry_mpi_t y, int x
     p34 = scanval ("3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
                    "BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
 
-  u   = mpi_new (0);
-  v   = mpi_new (0);
-  u3  = mpi_new (0);
-  v3  = mpi_new (0);
-  t   = mpi_new (0);
+  u   = mpi_new (ec->nbits);
+  v   = mpi_new (ec->nbits);
+  u3  = mpi_new (ec->nbits);
+  v3  = mpi_new (ec->nbits);
+  t   = mpi_new (ec->nbits);
 
   /* Compute u and v */
   /* u = y^2    */
@@ -300,10 +300,10 @@ _gcry_ecc_eddsa_recover_x (gcry_mpi_t x, gcry_mpi_t y,
   if (!seven)
     seven = mpi_set_ui (NULL, 7);
 
-  u   = mpi_new (0);
-  v   = mpi_new (0);
-  v3  = mpi_new (0);
-  t   = mpi_new (0);
+  u   = mpi_new (ec->nbits);
+  v   = mpi_new (ec->nbits);
+  v3  = mpi_new (ec->nbits);
+  t   = mpi_new (ec->nbits);
 
   /* Compute u and v */
   /* u = y^2    */
@@ -592,7 +592,7 @@ _gcry_ecc_eddsa_genkey (mpi_ec_t ec, int flags)
 {
   gpg_err_code_t rc;
   int b;
-  gcry_mpi_t a, x, y;
+  gcry_mpi_t a;
   mpi_point_struct Q;
   gcry_random_level_t random_level;
   char *dbuf;
@@ -616,8 +616,6 @@ _gcry_ecc_eddsa_genkey (mpi_ec_t ec, int flags)
   dlen = b;
 
   a = mpi_snew (0);
-  x = mpi_new (0);
-  y = mpi_new (0);
 
   /* Generate a secret.  */
   dbuf = _gcry_random_bytes_secure (dlen, random_level);
@@ -631,7 +629,7 @@ _gcry_ecc_eddsa_genkey (mpi_ec_t ec, int flags)
   /* log_printmpi ("ecgen         a", a); */
 
   /* Compute Q.  */
-  point_init (&Q);
+  point_init (&Q, ec->nbits);
   _gcry_mpi_ec_mul_point (&Q, a, ec->G, ec);
   if (DBG_CIPHER)
     log_printpnt ("ecgen      pk", &Q, ec);
@@ -643,8 +641,6 @@ _gcry_ecc_eddsa_genkey (mpi_ec_t ec, int flags)
 
  leave:
   _gcry_mpi_release (a);
-  _gcry_mpi_release (x);
-  _gcry_mpi_release (y);
   return rc;
 }
 
@@ -716,11 +712,11 @@ _gcry_ecc_eddsa_sign (gcry_mpi_t input, mpi_ec_t ec,
     return GPG_ERR_INV_DATA;
 
   /* Initialize some helpers.  */
-  point_init (&I);
+  point_init (&I, ec->nbits);
   a = mpi_snew (0);
-  x = mpi_new (0);
-  y = mpi_new (0);
-  r = mpi_snew (0);
+  x = mpi_new (ec->nbits);
+  y = mpi_new (ec->nbits);
+  r = mpi_snew (ec->nbits);
 
   rc = _gcry_ecc_eddsa_compute_h_d (&digest, ec);
   if (rc)
@@ -732,7 +728,7 @@ _gcry_ecc_eddsa_sign (gcry_mpi_t input, mpi_ec_t ec,
     {
       mpi_point_struct Q;
 
-      point_init (&Q);
+      point_init (&Q, ec->nbits);
       _gcry_mpi_ec_mul_point (&Q, a, ec->G, ec);
       ec->Q = mpi_point_snatch_set (NULL, Q.x, Q.y, Q.z);
     }
@@ -939,8 +935,8 @@ _gcry_ecc_eddsa_verify (gcry_mpi_t input, mpi_ec_t ec,
   else
     return GPG_ERR_NOT_IMPLEMENTED;
 
-  point_init (&Ia);
-  point_init (&Ib);
+  point_init (&Ia, ec->nbits);
+  point_init (&Ib, ec->nbits);
   h = mpi_new (0);
   s = mpi_new (0);
 
