--- libntfs/unix_io.c.orig	Mon Mar 21 12:16:42 2005
+++ libntfs/unix_io.c	Mon Mar 21 12:17:19 2005
@@ -72,6 +72,7 @@
 		flk.l_type = F_WRLCK;
 	flk.l_whence = SEEK_SET;
 	flk.l_start = flk.l_len = 0LL;
+#if 0
 	if (fcntl(DEV_FD(dev), F_SETLK, &flk)) {
 		err = errno;
 		Dprintf("ntfs_device_unix_io_open: Could not lock %s for %s: "
@@ -83,6 +84,7 @@
 					strerror(errno));
 		goto err_out;
 	}
+#endif
 	/* Set our open flag. */
 	NDevSetOpen(dev);
 	return 0;
@@ -108,9 +110,11 @@
 	flk.l_type = F_UNLCK;
 	flk.l_whence = SEEK_SET;
 	flk.l_start = flk.l_len = 0LL;
+#if 0
 	if (fcntl(DEV_FD(dev), F_SETLK, &flk))
 		Dprintf("ntfs_device_unix_io_close: Warning: Could not unlock "
 				"%s: %s\n", dev->d_name, strerror(errno));
+#endif
 	/* Close the file descriptor and clear our open flag. */
 	if (close(DEV_FD(dev)))
 		return -1;
