--- Band_DFT_Col.c.orig	2018-08-29 06:24:38 UTC
+++ Band_DFT_Col.c
@@ -483,9 +483,9 @@ double Band_DFT_Col(int SCF_iter,
 
     /* allocation */ 
 
-    stat_send = malloc(sizeof(MPI_Status)*numprocs2);
-    request_send = malloc(sizeof(MPI_Request)*numprocs2);
-    request_recv = malloc(sizeof(MPI_Request)*numprocs2);
+    stat_send = (MPI_Status *)malloc(sizeof(MPI_Status)*numprocs2);
+    request_send = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs2);
+    request_recv = (MPI_Request *)malloc(sizeof(MPI_Request)*numprocs2);
 
     is1 = (int*)malloc(sizeof(int)*numprocs2);
     ie1 = (int*)malloc(sizeof(int)*numprocs2);
