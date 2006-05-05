--- libntfs/unix_io.c.orig	Sat Feb  4 03:42:15 2006
+++ libntfs/unix_io.c	Thu May  4 03:59:59 2006
@@ -110,6 +110,7 @@
 		flk.l_type = F_WRLCK;
 	flk.l_whence = SEEK_SET;
 	flk.l_start = flk.l_len = 0LL;
+#if 0
 	if (fcntl(DEV_FD(dev), F_SETLK, &flk)) {
 		err = errno;
 		ntfs_log_debug("ntfs_device_unix_io_open: Could not lock %s for %s\n",
@@ -119,6 +120,7 @@
 					"close %s", dev->d_name);
 		goto err_out;
 	}
+#endif
 	/* Determine if device is a block device or not, ignoring errors. */
 	if (!fstat(DEV_FD(dev), &sbuf) && S_ISBLK(sbuf.st_mode))
 		NDevSetBlock(dev);
@@ -155,9 +157,11 @@
 	flk.l_type = F_UNLCK;
 	flk.l_whence = SEEK_SET;
 	flk.l_start = flk.l_len = 0LL;
+#if 0
 	if (fcntl(DEV_FD(dev), F_SETLK, &flk))
 		ntfs_log_perror("ntfs_device_unix_io_close: Warning: Could not "
 				"unlock %s", dev->d_name);
+#endif
 	/* Close the file descriptor and clear our open flag. */
 	if (close(DEV_FD(dev)))
 		return -1;
