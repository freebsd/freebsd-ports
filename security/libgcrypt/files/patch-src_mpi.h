--- src/mpi.h.orig	2025-11-27 09:08:47 UTC
+++ src/mpi.h
@@ -243,7 +243,7 @@ typedef struct gcry_mpi_point *mpi_point_t;
 typedef struct gcry_mpi_point mpi_point_struct;
 typedef struct gcry_mpi_point *mpi_point_t;
 
-void _gcry_mpi_point_init (mpi_point_t p);
+void _gcry_mpi_point_init (mpi_point_t p, unsigned int nbits);
 void _gcry_mpi_point_free_parts (mpi_point_t p);
 void _gcry_mpi_get_point (gcry_mpi_t x, gcry_mpi_t y, gcry_mpi_t z,
                           mpi_point_t point);
