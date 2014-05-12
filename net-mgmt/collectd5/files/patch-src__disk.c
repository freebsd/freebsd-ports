--- ./src/disk.c.orig	2014-01-26 08:09:14.856391000 +0000
+++ ./src/disk.c	2014-05-10 23:35:17.232681397 +0100
@@ -732,7 +732,8 @@
 
 #elif defined(HAVE_LIBSTATGRAB)
 	sg_disk_io_stats *ds;
-	int disks, counter;
+	size_t disks;
+	int counter;
 	char name[DATA_MAX_NAME_LEN];
 	
 	if ((ds = sg_get_disk_io_stats(&disks)) == NULL)
