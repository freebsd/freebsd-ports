--- Cluster_DFT.c.orig	2018-08-29 06:05:22 UTC
+++ Cluster_DFT.c
@@ -194,9 +194,9 @@ static double Cluster_collinear(
 
   Num_Comm_World1 = SpinP_switch + 1; 
 
-  stat_send = malloc(sizeof(MPI_Status)*numprocs0);
-  request_send = malloc(sizeof(MPI_Request)*numprocs0);
-  request_recv = malloc(sizeof(MPI_Request)*numprocs0);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*numprocs0);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs0);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs0);
 
   /***********************************************
       allocation of arrays for the first world 
@@ -1541,9 +1541,9 @@ static double Cluster_non_collinear(
 
   /* allocation of arrays */
 
-  stat_send = malloc(sizeof(MPI_Status)*numprocs);
-  request_send = malloc(sizeof(MPI_Request)*numprocs);
-  request_recv = malloc(sizeof(MPI_Request)*numprocs);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*numprocs);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs);
 
   /****************************************************
              calculation of the array size
@@ -2649,7 +2649,7 @@ void Save_DOS_Col(int n, int MaxN, int *
   MPI_Comm_size(mpi_comm_level1,&numprocs);
   MPI_Comm_rank(mpi_comm_level1,&myid);
 
-  request_recv = malloc(sizeof(MPI_Request)*numprocs);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs);
 
   /* open file pointers */
 
@@ -2901,7 +2901,7 @@ void Save_DOS_NonCol(int n, int MaxN, in
   MPI_Comm_size(mpi_comm_level1,&numprocs);
   MPI_Comm_rank(mpi_comm_level1,&myid);
 
-  request_recv = malloc(sizeof(MPI_Request)*numprocs);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs);
 
   /* open file pointers */
 
