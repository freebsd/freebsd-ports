--- Poisson.c.orig	2018-08-29 05:58:06 UTC
+++ Poisson.c
@@ -141,8 +141,8 @@ void FFT_Poisson(double *ReRhor, double 
     allocation of arrays:
   ****************************************************/
 
-  in  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
-  out = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
 
   /*------------------ FFT along the C-axis in the AB partition ------------------*/
 
@@ -182,10 +182,10 @@ void FFT_Poisson(double *ReRhor, double 
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
@@ -307,10 +307,10 @@ void FFT_Poisson(double *ReRhor, double 
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
@@ -503,8 +503,8 @@ void Inverse_FFT_Poisson(double *ReRhor,
     fftw_complex out[List_YOUSO[17]];
   ****************************************************/
 
-  in  = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
-  out = fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
+  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*List_YOUSO[17]); 
 
   /*------------------ Inverse FFT along the A-axis in the CB partition ------------------*/
 
@@ -544,10 +544,10 @@ void Inverse_FFT_Poisson(double *ReRhor,
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
@@ -669,10 +669,10 @@ void Inverse_FFT_Poisson(double *ReRhor,
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
