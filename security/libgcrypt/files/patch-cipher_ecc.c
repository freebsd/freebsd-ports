--- cipher/ecc.c.orig	2025-09-23 13:14:22 UTC
+++ cipher/ecc.c
@@ -256,7 +256,7 @@ nist_generate_key (mpi_ec_t ec, int flags,
   gcry_mpi_t x, y;
   const unsigned int pbits = ec->nbits;
 
-  point_init (&Q);
+  point_init (&Q, ec->nbits);
 
   if ((flags & PUBKEY_FLAG_TRANSIENT_KEY))
     random_level = GCRY_STRONG_RANDOM;
@@ -387,7 +387,7 @@ test_keys (mpi_ec_t ec, unsigned int nbits)
   if (DBG_CIPHER)
     log_debug ("Testing key.\n");
 
-  point_init (&R_);
+  point_init (&R_, ec->nbits);
 
   _gcry_mpi_randomize (test, nbits, GCRY_WEAK_RANDOM);
 
@@ -544,7 +544,7 @@ test_ecdh_only_keys (mpi_ec_t ec, unsigned int nbits, 
   if (DBG_CIPHER)
     log_debug ("Testing ECDH only key.\n");
 
-  point_init (&R_);
+  point_init (&R_, ec->nbits);
 
   if (ec->dialect == ECC_DIALECT_SAFECURVE || (flags & PUBKEY_FLAG_DJB_TWEAK))
     {
@@ -572,8 +572,8 @@ test_ecdh_only_keys (mpi_ec_t ec, unsigned int nbits, 
       _gcry_mpi_randomize (test, nbits, GCRY_WEAK_RANDOM);
     }
 
-  x0 = mpi_new (0);
-  x1 = mpi_new (0);
+  x0 = mpi_new (ec->nbits);
+  x1 = mpi_new (ec->nbits);
 
   /* R_ = hkQ  <=>  R_ = hkdG  */
   _gcry_mpi_ec_mul_point (&R_, test, ec->Q, ec);
@@ -617,12 +617,12 @@ check_secret_key (mpi_ec_t ec, int flags)
   gcry_mpi_t x2 = NULL;
   gcry_mpi_t y2 = NULL;
 
-  point_init (&Q);
-  x1 = mpi_new (0);
+  point_init (&Q, ec->nbits);
+  x1 = mpi_new (ec->nbits);
   if (ec->model == MPI_EC_MONTGOMERY)
     y1 = NULL;
   else
-    y1 = mpi_new (0);
+    y1 = mpi_new (ec->nbits);
 
   /* G in E(F_p) */
   if (!_gcry_mpi_ec_curve_point (ec->G, ec))
@@ -687,8 +687,8 @@ check_secret_key (mpi_ec_t ec, int flags)
     }
   else
     {
-      x2 = mpi_new (0);
-      y2 = mpi_new (0);
+      x2 = mpi_new (ec->nbits);
+      y2 = mpi_new (ec->nbits);
       if (_gcry_mpi_ec_get_affine (x2, y2, ec->Q, ec))
         {
           if (DBG_CIPHER)
@@ -751,8 +751,8 @@ ecc_generate (const gcry_sexp_t genparms, gcry_sexp_t 
     goto leave;
 
   /* Copy data to the result.  */
-  Gx = mpi_new (0);
-  Gy = mpi_new (0);
+  Gx = mpi_new (ec->nbits);
+  Gy = mpi_new (ec->nbits);
   if (ec->model != MPI_EC_MONTGOMERY)
     {
       if (_gcry_mpi_ec_get_affine (Gx, Gy, ec->G, ec))
@@ -787,8 +787,8 @@ ecc_generate (const gcry_sexp_t genparms, gcry_sexp_t 
         {
           /* This is the case for a key from _gcry_ecc_eddsa_generate
              with no compression.  */
-          Qx = mpi_new (0);
-          Qy = mpi_new (0);
+          Qx = mpi_new (ec->nbits);
+          Qy = mpi_new (ec->nbits);
           if (_gcry_mpi_ec_get_affine (Qx, Qy, ec->Q, ec))
             log_fatal ("ecgen: Failed to get affine coordinates for %s\n", "Q");
         }
@@ -1369,13 +1369,13 @@ ecc_encrypt_raw (gcry_sexp_t *r_ciph, gcry_sexp_t s_da
     unsigned int rawmpilen;
 
     rc = 0;
-    x = mpi_new (0);
+    x = mpi_new (ec->nbits);
     if (ec->model == MPI_EC_MONTGOMERY)
       y = NULL;
     else
-      y = mpi_new (0);
+      y = mpi_new (ec->nbits);
 
-    point_init (&R);
+    point_init (&R, ec->nbits);
 
     /* R = kQ  <=>  R = kdG  */
     _gcry_mpi_ec_mul_point (&R, data, ec->Q, ec);
@@ -1478,12 +1478,13 @@ ecc_decrypt_raw (gcry_sexp_t *r_plain, gcry_sexp_t s_d
   int flags = GCRYECC_FLAG_LEAST_LEAK;
   int enable_specific_point_validation;
 
-  point_init (&kG);
-  point_init (&R);
+  nbits = ecc_get_nbits (keyparms);
 
-  _gcry_pk_util_init_encoding_ctx (&ctx, PUBKEY_OP_DECRYPT,
-                                   (nbits = ecc_get_nbits (keyparms)));
+  point_init (&kG, nbits);
+  point_init (&R, nbits);
 
+  _gcry_pk_util_init_encoding_ctx (&ctx, PUBKEY_OP_DECRYPT, nbits);
+
   /*
    * Extract the key.
    */
@@ -1564,11 +1565,11 @@ ecc_decrypt_raw (gcry_sexp_t *r_plain, gcry_sexp_t s_d
   {
     gcry_mpi_t x, y;
 
-    x = mpi_new (0);
+    x = mpi_new (ec->nbits);
     if (ec->model == MPI_EC_MONTGOMERY)
       y = NULL;
     else
-      y = mpi_new (0);
+      y = mpi_new (ec->nbits);
 
     if (_gcry_mpi_ec_get_affine (x, y, &R, ec))
       {
@@ -1887,10 +1888,10 @@ compute_keygrip (gcry_md_hd_t md, gcry_sexp_t keyparms
            * Recover Y.  The Weierstrass curve: y^2 = x^3 + a*x + b
            */
 
-          x3 = mpi_new (0);
-          t = mpi_new (0);
-          p1_4 = mpi_new (0);
-          y = mpi_new (0);
+          x3 = mpi_new (ec->nbits);
+          t = mpi_new (ec->nbits);
+          p1_4 = mpi_new (ec->nbits);
+          y = mpi_new (ec->nbits);
 
           /* Compute right hand side.  */
           mpi_powm (x3, x, mpi_const (MPI_C_THREE), ec->p);
