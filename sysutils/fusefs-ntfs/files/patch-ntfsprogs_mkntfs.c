--- ntfsprogs/mkntfs.c.orig	2015-03-14 14:10:12 UTC
+++ ntfsprogs/mkntfs.c
@@ -3488,6 +3488,7 @@ static BOOL mkntfs_open_partition(ntfs_v
 		goto done;
 	}
 
+#ifndef __FreeBSD__
 	if (!S_ISBLK(sbuf.st_mode)) {
 		ntfs_log_error("%s is not a block device.\n", vol->dev->d_name);
 		if (!opts.force) {
@@ -3526,6 +3527,7 @@ static BOOL mkntfs_open_partition(ntfs_v
 		ntfs_log_warning("mkntfs forced anyway.\n");
 #endif
 	}
+#endif
 	/* Make sure the file system is not mounted. */
 	if (ntfs_check_if_mounted(vol->dev->d_name, &mnt_flags)) {
 		ntfs_log_perror("Failed to determine whether %s is mounted", vol->dev->d_name);
