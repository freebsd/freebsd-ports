--- ./src/mpi/romio/adio/ad_hfs/ad_hfs_fcntl.c.orig	2007-11-02 23:50:19.000000000 +0100
+++ ./src/mpi/romio/adio/ad_hfs/ad_hfs_fcntl.c	2008-04-07 23:19:28.000000000 +0200
@@ -20,7 +20,11 @@
 
     switch(flag) {
     case ADIO_FCNTL_GET_FSIZE:
+#ifdef __FreeBSD__
+	fcntl_struct->fsize = lseek(fd->fd_sys, 0, SEEK_END);
+#else
 	fcntl_struct->fsize = lseek64(fd->fd_sys, 0, SEEK_END);
+#endif
 #ifdef HPUX
 	if (fd->fp_sys_posn != -1) 
 	     lseek64(fd->fd_sys, fd->fp_sys_posn, SEEK_SET);
