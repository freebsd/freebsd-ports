--- src/compositor-x11.c.orig	2016-05-19 21:36:04 UTC
+++ src/compositor-x11.c
@@ -742,7 +742,11 @@ x11_output_init_shm(struct x11_backend *
 
 
 	/* Create SHM segment and attach it */
+#if defined(__FreeBSD__)
+	output->shm_id = shmget(IPC_PRIVATE, width * height * (bitsperpixel / 8), IPC_CREAT | SHM_R | SHM_W);
+#else
 	output->shm_id = shmget(IPC_PRIVATE, width * height * (bitsperpixel / 8), IPC_CREAT | S_IRWXU);
+#endif
 	if (output->shm_id == -1) {
 		weston_log("x11shm: failed to allocate SHM segment\n");
 		return -1;
