--- Poisson.c.orig	2021-08-12 13:42:04 UTC
+++ Poisson.c
@@ -209,8 +209,8 @@ void FFT_Poisson(double *ReRhor, double *ImRhor, 
     allocation of arrays:
   ****************************************************/
 
-  in  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
-  out = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
 
   ReTmp = (double*)malloc(sizeof(double)*My_NumGridB_AB);
   ImTmp = (double*)malloc(sizeof(double)*My_NumGridB_AB);
@@ -260,10 +260,10 @@ void FFT_Poisson(double *ReRhor, double *ImRhor, 
   array0 = (double*)malloc(sizeof(double)*2*GP_B_AB2CA_S[NN_B_AB2CA_S]); 
   array1 = (double*)malloc(sizeof(double)*2*GP_B_AB2CA_R[NN_B_AB2CA_R]); 
 
-  request_send = malloc(sizeof(MPI_Request)*NN_B_AB2CA_S);
-  request_recv = malloc(sizeof(MPI_Request)*NN_B_AB2CA_R);
-  stat_send = malloc(sizeof(MPI_Status)*NN_B_AB2CA_S);
-  stat_recv = malloc(sizeof(MPI_Status)*NN_B_AB2CA_R);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_AB2CA_S);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_AB2CA_R);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_AB2CA_S);
+  stat_recv = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_AB2CA_R);
 
   NN_S = 0;
   NN_R = 0;
@@ -385,10 +385,10 @@ void FFT_Poisson(double *ReRhor, double *ImRhor, 
   array0 = (double*)malloc(sizeof(double)*2*GP_B_CA2CB_S[NN_B_CA2CB_S]); 
   array1 = (double*)malloc(sizeof(double)*2*GP_B_CA2CB_R[NN_B_CA2CB_R]); 
 
-  request_send = malloc(sizeof(MPI_Request)*NN_B_CA2CB_S);
-  request_recv = malloc(sizeof(MPI_Request)*NN_B_CA2CB_R);
-  stat_send = malloc(sizeof(MPI_Status)*NN_B_CA2CB_S);
-  stat_recv = malloc(sizeof(MPI_Status)*NN_B_CA2CB_R);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_CA2CB_S);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_CA2CB_R);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_CA2CB_S);
+  stat_recv = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_CA2CB_R);
 
   NN_S = 0;
   NN_R = 0;
@@ -592,8 +592,8 @@ void Inverse_FFT_Poisson(double *ReRhor, double *ImRho
     fftw_complex out[List_YOUSO[17]];
   ****************************************************/
 
-  in  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
-  out = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
 
   ReTmp = (double*)malloc(sizeof(double)*My_NumGridB_CB);
   ImTmp = (double*)malloc(sizeof(double)*My_NumGridB_CB);
@@ -643,10 +643,10 @@ void Inverse_FFT_Poisson(double *ReRhor, double *ImRho
   array0 = (double*)malloc(sizeof(double)*2*GP_B_CA2CB_R[NN_B_CA2CB_R]); 
   array1 = (double*)malloc(sizeof(double)*2*GP_B_CA2CB_S[NN_B_CA2CB_S]); 
 
-  request_send = malloc(sizeof(MPI_Request)*NN_B_CA2CB_R);
-  request_recv = malloc(sizeof(MPI_Request)*NN_B_CA2CB_S);
-  stat_send = malloc(sizeof(MPI_Status)*NN_B_CA2CB_R);
-  stat_recv = malloc(sizeof(MPI_Status)*NN_B_CA2CB_S);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_CA2CB_R);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_CA2CB_S);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_CA2CB_R);
+  stat_recv = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_CA2CB_S);
 
   NN_S = 0;
   NN_R = 0;
@@ -768,10 +768,10 @@ void Inverse_FFT_Poisson(double *ReRhor, double *ImRho
   array0 = (double*)malloc(sizeof(double)*2*GP_B_AB2CA_R[NN_B_AB2CA_R]); 
   array1 = (double*)malloc(sizeof(double)*2*GP_B_AB2CA_S[NN_B_AB2CA_S]); 
 
-  request_send = malloc(sizeof(MPI_Request)*NN_B_AB2CA_R);
-  request_recv = malloc(sizeof(MPI_Request)*NN_B_AB2CA_S);
-  stat_send = malloc(sizeof(MPI_Status)*NN_B_AB2CA_R);
-  stat_recv = malloc(sizeof(MPI_Status)*NN_B_AB2CA_S);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_AB2CA_R);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*NN_B_AB2CA_S);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_AB2CA_R);
+  stat_recv = (MPI_Status *)malloc(sizeof(MPI_Status)*NN_B_AB2CA_S);
 
   NN_S = 0;
   NN_R = 0;
