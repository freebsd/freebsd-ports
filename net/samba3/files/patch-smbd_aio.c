--- smbd/aio.c.orig	Tue Jan  3 03:03:05 2006
+++ smbd/aio.c	Tue Jan  3 03:06:52 2006
@@ -25,7 +25,17 @@
 
 /* The signal we'll use to signify aio done. */
 #ifndef RT_SIGNAL_AIO
-#define RT_SIGNAL_AIO (SIGRTMIN+3)
+#ifndef SIGRTMIN
+#define SIGRTMIN	NSIG
+#endif
+#define RT_SIGNAL_AIO	(SIGRTMIN+3)
+#endif
+
+#ifndef HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIVAL_PTR
+#ifdef HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIGVAL_PTR
+#define sival_int	sigval_int
+#define sival_ptr	sigval_ptr
+#endif
 #endif
 
 /****************************************************************************
@@ -497,6 +507,11 @@
 static BOOL handle_aio_completed(struct aio_extra *aio_ex, int *perr)
 {
 	int err;
+	
+	if(!aio_ex) {
+	        DEBUG(3, ("handle_aio_completed: Non-existing aio_ex passed\n"));
+		return False;
+	}
 
 	/* Ensure the operation has really completed. */
 	if (SMB_VFS_AIO_ERROR(aio_ex->fsp, &aio_ex->acb) == EINPROGRESS) {
