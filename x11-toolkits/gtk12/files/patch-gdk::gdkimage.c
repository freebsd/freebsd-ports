--- gdk/gdkimage.c.orig	Wed Dec 19 08:39:12 2001
+++ gdk/gdkimage.c	Wed Dec 19 08:39:19 2001
@@ -213,7 +213,7 @@
 
 	      x_shm_info->shmid = shmget (IPC_PRIVATE,
 					  private->ximage->bytes_per_line * private->ximage->height,
-					  IPC_CREAT | 0777);
+					  IPC_CREAT | SHM_R | SHM_W);
 
 	      if (x_shm_info->shmid == -1)
 		{
