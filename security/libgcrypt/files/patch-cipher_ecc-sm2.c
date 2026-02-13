--- cipher/ecc-sm2.c.orig	2021-02-12 11:23:24 UTC
+++ cipher/ecc-sm2.c
@@ -114,12 +114,12 @@ _gcry_ecc_sm2_encrypt (gcry_sexp_t *r_ciph, gcry_mpi_t
   unsigned char *cipher = NULL;
   int i;
 
-  point_init (&kG);
-  point_init (&kP);
-  x1 = mpi_new (0);
-  y1 = mpi_new (0);
-  x2 = mpi_new (0);
-  y2 = mpi_new (0);
+  point_init (&kG, ec->nbits);
+  point_init (&kP, ec->nbits);
+  x1 = mpi_new (ec->nbits);
+  y1 = mpi_new (ec->nbits);
+  x2 = mpi_new (ec->nbits);
+  y2 = mpi_new (ec->nbits);
 
   in = _gcry_mpi_get_buffer (input, 0, &inlen, NULL);
   if (!in)
@@ -268,10 +268,10 @@ _gcry_ecc_sm2_decrypt (gcry_sexp_t *r_plain, gcry_sexp
     unsigned int c3_len;
     int i;
 
-    point_init (&c1);
-    point_init (&kP);
-    x2 = mpi_new (0);
-    y2 = mpi_new (0);
+    point_init (&c1, ec->nbits);
+    point_init (&kP, ec->nbits);
+    x2 = mpi_new (ec->nbits);
+    y2 = mpi_new (ec->nbits);
 
     in = mpi_get_opaque (data_c2, &inlen);
     inlen = (inlen + 7) / 8;
@@ -401,10 +401,10 @@ _gcry_ecc_sm2_sign (gcry_mpi_t input, mpi_ec_t ec,
   if (rc)
     return rc;
 
-  point_init (&kG);
-  x1 = mpi_new (0);
-  rk = mpi_new (0);
-  tmp = mpi_new (0);
+  point_init (&kG, ec->nbits);
+  x1 = mpi_new (ec->nbits);
+  rk = mpi_new (ec->nbits);
+  tmp = mpi_new (ec->nbits);
 
   for (;;)
     {
@@ -514,11 +514,11 @@ _gcry_ecc_sm2_verify (gcry_mpi_t input, mpi_ec_t ec,
   if (err)
     return err;
 
-  point_init (&sG);
-  point_init (&tP);
-  x1 = mpi_new (0);
-  y1 = mpi_new (0);
-  t = mpi_new (0);
+  point_init (&sG, ec->nbits);
+  point_init (&tP, ec->nbits);
+  x1 = mpi_new (ec->nbits);
+  y1 = mpi_new (ec->nbits);
+  t = mpi_new (ec->nbits);
 
   /* t = (r + s) % n, t != 0 */
   mpi_addm (t, r, s, ec->n);
