--- cipher/ecc-curves.c.orig	2025-05-08 06:47:34 UTC
+++ cipher/ecc-curves.c
@@ -863,7 +863,7 @@ _gcry_ecc_get_curve (gcry_sexp_t keyparms, int iterato
   if (rc)
     goto leave;
 
-  _gcry_mpi_point_init (&E.G);
+  _gcry_mpi_point_init (&E.G, 0);
   _gcry_mpi_point_set (&E.G, G->x, G->y, G->z);
 
   for (idx = 0; domain_parms[idx].desc; idx++)
@@ -1120,7 +1120,7 @@ mpi_ec_get_elliptic_curve (elliptic_curve_t *E, int *r
             goto leave;
           if (G)
             {
-              _gcry_mpi_point_init (&E->G);
+              _gcry_mpi_point_init (&E->G, 0);
               mpi_point_set (&E->G, G->x, G->y, G->z);
               mpi_point_set (G, NULL, NULL, NULL);
               mpi_point_release (G);
