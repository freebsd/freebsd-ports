--- src/ntfs_io.c.orig	2023-08-08 15:12:08 UTC
+++ src/ntfs_io.c
@@ -154,7 +154,7 @@ static int ntfs_device_testdisk_io_stat(struct ntfs_de
 	return -1;
 }
 
-static int ntfs_device_testdisk_io_ioctl(struct ntfs_device *dev, int request,
+static int ntfs_device_testdisk_io_ioctl(struct ntfs_device *dev, unsigned long request,
 		void *argp)
 {
 	log_warning( "ntfs_device_testdisk_io_ioctl() unimplemented\n");
