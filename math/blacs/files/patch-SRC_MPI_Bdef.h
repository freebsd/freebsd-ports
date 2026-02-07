--- SRC/MPI/Bdef.h.orig	1998-03-13 20:14:33 UTC
+++ SRC/MPI/Bdef.h
@@ -322,6 +322,15 @@ int BI_ContxtNum(BLACSCONTEXT *ctxt);
 void BI_BlacsWarn(int ConTxt, int line, char *file, char *form, ...);
 void BI_BlacsErr(int ConTxt, int line, char *file, char *form, ...);
 int BI_ContxtNum(BLACSCONTEXT *ctxt);
+void BI_TransDist(BLACSCONTEXT *ctxt, char scope, int m, int n, int *rA,
+                  int *cA, int ldrc, BI_DistType *dist, int rdest, int cdest);
+void BI_dmvcopy(int m, int n, double *A, int lda, double *buff);
+void BI_dvmcopy(int m, int n, double *A, int lda, double *buff);
+void BI_imvcopy(int m, int n, int *A, int lda, int *buff);
+void BI_ivmcopy(int m, int n, int *A, int lda, int *buff);
+void BI_smvcopy(int m, int n, float *A, int lda, float *buff);
+void BI_svmcopy(int m, int n, float *A, int lda, float *buff);
+void Cblacs_pinfo(int *mypnum, int *nprocs);
 #else
 void BI_BlacsWarn();
 void BI_BlacsErr();
@@ -1605,9 +1614,9 @@ int BI_ContxtNum();
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
 
