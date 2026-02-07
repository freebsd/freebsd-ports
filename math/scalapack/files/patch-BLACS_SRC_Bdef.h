--- BLACS/SRC/Bdef.h.orig	2024-08-06 11:44:11 UTC
+++ BLACS/SRC/Bdef.h
@@ -129,6 +129,15 @@ Int BI_ContxtNum(BLACSCONTEXT *ctxt);
 void BI_BlacsWarn(Int ConTxt, Int line, char *file, char *form, ...);
 void BI_BlacsErr(Int ConTxt, Int line, char *file, char *form, ...);
 Int BI_ContxtNum(BLACSCONTEXT *ctxt);
+void BI_TransDist(BLACSCONTEXT *ctxt, char scope, Int m, Int n, Int *rA,
+                  Int *cA, Int ldrc, BI_DistType *dist, Int rdest, Int cdest);
+void BI_dmvcopy(Int m, Int n, double *A, Int lda, double *buff);
+void BI_dvmcopy(Int m, Int n, double *A, Int lda, double *buff);
+void BI_imvcopy(Int m, Int n, Int *A, Int lda, Int *buff);
+void BI_ivmcopy(Int m, Int n, Int *A, Int lda, Int *buff);
+void BI_smvcopy(Int m, Int n, float *A, Int lda, float *buff);
+void BI_svmcopy(Int m, Int n, float *A, Int lda, float *buff);
+void Cblacs_pinfo(Int *mypnum, Int *nprocs);
 
 /*
  * If we've got an ANSI standard C compiler, we can use void pointers...
