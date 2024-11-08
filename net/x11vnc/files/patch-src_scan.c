--- src/scan.c.orig	2019-01-05 13:22:11 UTC
+++ src/scan.c
@@ -320,7 +320,7 @@ static int shm_create(XShmSegmentInfo *shm, XImage **x
 
 #if HAVE_XSHM
 	shm->shmid = shmget(IPC_PRIVATE,
-	    xim->bytes_per_line * xim->height, IPC_CREAT | 0777);
+	    xim->bytes_per_line * xim->height, IPC_CREAT | 0600);
 
 	if (shm->shmid == -1) {
 		rfbErr("shmget(%s) failed.\n", name);
