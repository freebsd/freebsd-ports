--- ntfsprogs/mkntfs.c	2007-09-19 18:51:09.000000000 +0200
+++ ntfsprogs/mkntfs.c	2010-03-16 17:26:42.000000000 +0100
@@ -552,12 +552,16 @@
 	total = 0LL;
 	retry = 0;
 	do {
-		bytes_written = dev->d_ops->write(dev, b, count);
+		bytes_written = (long long)dev->d_ops->write(dev, b, count);
 		if (bytes_written == -1LL) {
 			retry = errno;
 			ntfs_log_perror("Error writing to %s", dev->d_name);
 			errno = retry;
 			return bytes_written;
+	    	} else if (bytes_written < 0) {
+			errno = EINVAL;
+			ntfs_log_error("Failed to write to device %s.\n", dev->d_name);
+			return -1;
 		} else if (!bytes_written) {
 			retry++;
 		} else {
@@ -3072,8 +3076,8 @@
 		goto done;
 	}
 
-	if (!S_ISBLK(sbuf.st_mode)) {
-		ntfs_log_error("%s is not a block device.\n", vol->dev->d_name);
+	if (!S_ISCHR(sbuf.st_mode)) {
+		ntfs_log_error("%s is not a character device.\n", vol->dev->d_name);
 		if (!opts.force) {
 			ntfs_log_error("Refusing to make a filesystem here!\n");
 			goto done;
