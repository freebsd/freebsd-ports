--- mpi/ec.c.orig	2026-01-20 13:36:28 UTC
+++ mpi/ec.c
@@ -33,7 +33,7 @@ extern void reverse_buffer (unsigned char *buffer, uns
 
 extern void reverse_buffer (unsigned char *buffer, unsigned int length);
 
-#define point_init(a)  _gcry_mpi_point_init ((a))
+#define point_init(a, nbits)  _gcry_mpi_point_init ((a), (nbits))
 #define point_free(a)  _gcry_mpi_point_free_parts ((a))
 
 
@@ -55,8 +55,8 @@ _gcry_mpi_point_log (const char *name, mpi_point_t poi
 
   if (ctx)
     {
-      x = mpi_new (0);
-      y = mpi_new (0);
+      x = mpi_new (ctx->nbits);
+      y = mpi_new (ctx->nbits);
     }
   if (!ctx || _gcry_mpi_ec_get_affine (x, y, point, ctx))
     {
@@ -90,10 +90,8 @@ _gcry_mpi_point_new (unsigned int nbits)
 {
   mpi_point_t p;
 
-  (void)nbits;  /* Currently not used.  */
-
   p = xmalloc (sizeof *p);
-  _gcry_mpi_point_init (p);
+  _gcry_mpi_point_init (p, nbits);
   return p;
 }
 
@@ -113,11 +111,11 @@ void
 /* Initialize the fields of a point object.  gcry_mpi_point_free_parts
    may be used to release the fields.  */
 void
-_gcry_mpi_point_init (mpi_point_t p)
+_gcry_mpi_point_init (mpi_point_t p, unsigned int nbits)
 {
-  p->x = mpi_new (0);
-  p->y = mpi_new (0);
-  p->z = mpi_new (0);
+  p->x = mpi_new (nbits);
+  p->y = mpi_new (nbits);
+  p->z = mpi_new (nbits);
 }
 
 
@@ -1213,8 +1211,8 @@ _gcry_mpi_ec_get_affine (gcry_mpi_t x, gcry_mpi_t y, m
         saved_flags = ctx->flags;
         ctx->flags |= GCRYECC_FLAG_LEAST_LEAK;
 
-        z1 = mpi_new (0);
-        z2 = mpi_new (0);
+        z1 = mpi_new (ctx->nbits);
+        z2 = mpi_new (ctx->nbits);
         ec_invm (z1, point->z, ctx);   /* z1 = z^(-1) mod p  */
         ec_mulm_lli (z2, z1, z1, ctx); /* z2 = z^(-2) mod p  */
 
@@ -1229,7 +1227,7 @@ _gcry_mpi_ec_get_affine (gcry_mpi_t x, gcry_mpi_t y, m
           {
             mpi_resize (point->y, ctx->p->nlimbs);
             point->y->nlimbs = ctx->p->nlimbs;
-            z3 = mpi_new (0);
+            z3 = mpi_new (ctx->nbits);
             ec_mulm_lli (z3, z2, z1, ctx); /* z3 = z^(-3) mod p  */
             ec_mulm_lli (y, point->y, z3, ctx);
             mpi_free (z3);
@@ -1269,7 +1267,7 @@ _gcry_mpi_ec_get_affine (gcry_mpi_t x, gcry_mpi_t y, m
 	    return 0;
 	  }
 
-        z = mpi_new (0);
+        z = mpi_new (ctx->nbits);
         ec_invm (z, point->z, ctx);
 
         mpi_resize (z, ctx->p->nlimbs);
@@ -2111,10 +2109,10 @@ montgomery_mul_point (mpi_point_t result,
   int scalar_copied = 0;
 
   nbits = mpi_get_nbits (scalar);
-  point_init (&p1);
-  point_init (&p2);
-  point_init (&p1_);
-  point_init (&p2_);
+  point_init (&p1, ctx->nbits);
+  point_init (&p2, ctx->nbits);
+  point_init (&p1_, ctx->nbits);
+  point_init (&p2_, ctx->nbits);
   mpi_set_ui (p1.x, 1);
   mpi_free (p2.x);
   p2.x  = mpi_copy (point->x);
@@ -2184,7 +2182,7 @@ montgomery_mul_point (mpi_point_t result,
     }
   else
     {
-      z1 = mpi_new (0);
+      z1 = mpi_new (ctx->nbits);
       ec_invm (z1, p1.z, ctx);
       ec_mulm (result->x, p1.x, z1, ctx);
       mpi_set_ui (result->z, 1);
@@ -2216,13 +2214,13 @@ mpi_ec_mul_point_lli (mpi_point_t result,
 
   /* Convert POINT1 into affine coordinate, so that we can use
      add_points_*_a routine with affine coordinate.  */
-  point_init (point);
+  point_init (point, ctx->nbits);
   if (_gcry_mpih_cmp_ui (point1->z->d, ctx->p->nlimbs, 1))
     {
       gcry_mpi_t x, y;
 
-      x = mpi_new (0);
-      y = mpi_new (0);
+      x = mpi_new (ctx->nbits);
+      y = mpi_new (ctx->nbits);
 
       if (_gcry_mpi_ec_get_affine (x, y, point1, ctx))
         {
@@ -2261,7 +2259,7 @@ mpi_ec_mul_point_lli (mpi_point_t result,
       mpi_set_ui (result->z, 1);
     }
 
-  point_init (&tmppnt);
+  point_init (&tmppnt, ctx->nbits);
   mpi_point_resize (result, ctx);
   mpi_point_resize (&tmppnt, ctx);
   if (ctx->model == MPI_EC_WEIERSTRASS)
@@ -2418,8 +2416,8 @@ _gcry_mpi_ec_mul_point (mpi_point_t result,
   p1.x = x1; x1 = NULL;
   p1.y = y1; y1 = NULL;
   p1.z = z1; z1 = NULL;
-  point_init (&p2);
-  point_init (&p1inv);
+  point_init (&p2, ctx->nbits);
+  point_init (&p1inv, ctx->nbits);
 
   /* Invert point: y = p - y mod p  */
   point_set (&p1inv, &p1);
@@ -2455,9 +2453,9 @@ _gcry_mpi_ec_curve_point (gcry_mpi_point_t point, mpi_
   int res = 0;
   gcry_mpi_t x, y, w;
 
-  x = mpi_new (0);
-  y = mpi_new (0);
-  w = mpi_new (0);
+  x = mpi_new (ctx->nbits);
+  y = mpi_new (ctx->nbits);
+  w = mpi_new (ctx->nbits);
 
   /* Check that the point is in range.  This needs to be done here and
    * not after conversion to affine coordinates.  */
@@ -2477,7 +2475,7 @@ _gcry_mpi_ec_curve_point (gcry_mpi_point_t point, mpi_
         if (_gcry_mpi_ec_get_affine (x, y, point, ctx))
           goto leave;
 
-        xxx = mpi_new (0);
+        xxx = mpi_new (ctx->nbits);
 
         /* y^2 == x^3 + a·x + b */
         ec_pow2 (y, y, ctx);
