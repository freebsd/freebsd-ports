--- ./src/mpi/romio/adio/common/ad_write_nolock.c.orig	2008-03-10 23:38:31.000000000 +0100
+++ ./src/mpi/romio/adio/common/ad_write_nolock.c	2008-04-07 23:21:55.000000000 +0200
@@ -89,9 +89,15 @@
 	/* seek to the right spot in the file */
 	if (file_ptr_type == ADIO_EXPLICIT_OFFSET) {
 	    off = fd->disp + etype_size * offset;
+#ifdef __FreeBSD__
+	    lseek(fd->fd_sys, off, SEEK_SET);
+	}
+	else off = lseek(fd->fd_sys, fd->fp_ind, SEEK_SET);
+#else
 	    lseek64(fd->fd_sys, off, SEEK_SET);
 	}
 	else off = lseek64(fd->fd_sys, fd->fp_ind, SEEK_SET);
+#endif
 
 	/* loop through all the flattened pieces.  combine into buffer until
 	 * no more will fit, then write.
