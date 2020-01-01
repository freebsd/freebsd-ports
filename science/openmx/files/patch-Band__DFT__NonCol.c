--- Band_DFT_NonCol.c.orig	2018-08-29 06:26:10 UTC
+++ Band_DFT_NonCol.c
@@ -554,9 +554,9 @@ double Band_DFT_NonCol(int SCF_iter,
 
     /* allocation */ 
 
-    stat_send = malloc(sizeof(MPI_Status)*numprocs1);
-    request_send = malloc(sizeof(MPI_Request)*numprocs1);
-    request_recv = malloc(sizeof(MPI_Request)*numprocs1);
+    stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*numprocs1);
+    request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs1);
+    request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs1);
 
     is1 = (int*)malloc(sizeof(int)*numprocs1);
     ie1 = (int*)malloc(sizeof(int)*numprocs1);
