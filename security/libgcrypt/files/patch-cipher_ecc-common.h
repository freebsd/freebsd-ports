--- cipher/ecc-common.h.orig	2022-01-25 21:55:44 UTC
+++ cipher/ecc-common.h
@@ -47,7 +47,7 @@ point_set (mpi_point_t d, mpi_point_t s)
   mpi_set (d->z, s->z);
 }
 
-#define point_init(a)  _gcry_mpi_point_init ((a))
+#define point_init(a,nbits)  _gcry_mpi_point_init ((a),(nbits))
 #define point_free(a)  _gcry_mpi_point_free_parts ((a))
 
 
