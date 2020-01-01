--- Poisson_ESM.c.orig	2018-08-29 06:03:16 UTC
+++ Poisson_ESM.c
@@ -71,8 +71,8 @@ double Poisson_ESM(int fft_charge_flag,
     fftw_complex out[List_YOUSO[17]];
   ****************************************************/
 
-  in0  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
-  out0 = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
+  in0  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
+  out0 = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
 
 
   if (myid==Host_ID) { 
@@ -908,8 +908,8 @@ void One_dim_FFT(FILE *fp, 
     fftw_complex out[List_YOUSO[17]];
   ****************************************************/
 
-  in  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
-  out = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
+  in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
+  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]);
 
   p = fftw_plan_dft_1d(Ngrid1, in, out, sgn2, FFTW_ESTIMATE);
 
