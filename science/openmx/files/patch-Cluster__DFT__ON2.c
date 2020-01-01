--- Cluster_DFT_ON2.c.orig	2016-03-27 06:53:28 UTC
+++ Cluster_DFT_ON2.c
@@ -10,6 +10,7 @@
 
 ***********************************************************************/
 
+#include <complex.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -1275,9 +1276,9 @@ static void OND_Solver(
   MPI_Request *request_send;
   MPI_Request *request_recv;
 
-  stat_send = malloc(sizeof(MPI_Status)*numprocs2);
-  request_send = malloc(sizeof(MPI_Request)*numprocs2);
-  request_recv = malloc(sizeof(MPI_Request)*numprocs2);
+  stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*numprocs2);
+  request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs2);
+  request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs2);
 
   al.r = 1.0;
   al.i = 0.0;
