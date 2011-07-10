--- ntfsprogs/ntfsclone.3	2011-04-10 20:04:41.000000000 +0200
+++ ntfsprogs/ntfsclone.c	2011-04-25 14:06:11.000000000 +0200
@@ -89,6 +89,10 @@
 #define BLKGETSIZE64	_IOR(0x12,114,size_t)	/* Get device size in bytes. */
 #endif
 
+#ifdef __sun
+#define NO_STATFS 1	/* statfs(2) and f_type are not universal */
+#endif
+
 static const char *EXEC_NAME = "ntfsclone";
 
 static const char *bad_sectors_warning_msg =
@@ -119,7 +123,9 @@
 	int restore_image;
 	char *output;
 	char *volume;
+#ifndef NO_STATFS
 	struct statfs stfs;
+#endif
 } opt;
 
 struct bitmap {
@@ -629,6 +635,7 @@
 	}
 
 	if (write_all(&fd_out, buff, csize) == -1) {
+#ifndef NO_STATFS
 		int err = errno;
 		perr_printf("Write failed");
 		if (err == EIO && opt.stfs.f_type == 0x517b)
@@ -637,6 +644,9 @@
 			       "efficient sparse file handling by default. "
 			       "Please try a different method.\n");
 		exit(1);
+#else
+		perr_printf("Write failed");
+#endif
 	}
 }
 
@@ -1565,6 +1575,7 @@
 
 static void set_filesize(s64 filesize)
 {
+#ifndef NO_STATFS
 	long fs_type = 0; /* Unknown filesystem type */
 
 	if (fstatfs(fd_out, &opt.stfs) == -1)
@@ -1582,22 +1593,27 @@
 		Printf("WARNING: You're using SMBFS and if the remote share "
 		       "isn't Samba but a Windows\ncomputer then the clone "
 		       "operation will be very inefficient and may fail!\n");
+#endif
 
 	if (ftruncate(fd_out, filesize) == -1) {
 		int err = errno;
 		perr_printf("ftruncate failed for file '%s'", opt.output);
+#ifndef NO_STATFS
 		if (fs_type)
 			Printf("Destination filesystem type is 0x%lx.\n",
 			       (unsigned long)fs_type);
+#endif
 		if (err == E2BIG) {
 			Printf("Your system or the destination filesystem "
 			       "doesn't support large files.\n");
+#ifndef NO_STATFS
 			if (fs_type == 0x517b) {
 				Printf("SMBFS needs minimum Linux kernel "
 				       "version 2.4.25 and\n the 'lfs' option"
 				       "\nfor smbmount to have large "
 				       "file support.\n");
 			}
+#endif
 		} else if (err == EPERM) {
 			Printf("Apparently the destination filesystem doesn't "
 			       "support sparse files.\nYou can overcome this "
