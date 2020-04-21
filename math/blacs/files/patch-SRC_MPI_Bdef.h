--- SRC/MPI/Bdef.h.orig	2020-04-21 20:22:36 UTC
+++ SRC/MPI/Bdef.h
@@ -1605,9 +1605,9 @@ int BI_ContxtNum();
 #else
 #define BI_MPI_Type_struct(count_, lens_, disps_, types_, newtype_, ierr_) \
 { \
-   (ierr_) = MPI_Type_struct((count_), (lens_), (disps_), (types_), \
+   (ierr_) = MPI_Type_create_struct((count_), (lens_), (disps_), (types_), \
                              (newtype_)); \
-   Mmpierror((ierr_), "MPI_Type_struct", NULL, __LINE__, __FILE__); \
+   Mmpierror((ierr_), "MPI_Type_create_struct", NULL, __LINE__, __FILE__); \
 }
 #endif
 
