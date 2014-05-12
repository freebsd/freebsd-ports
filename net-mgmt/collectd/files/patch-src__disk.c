--- ./src/disk.c.orig	2013-11-23 22:36:13.757103756 +0000
+++ ./src/disk.c	2013-11-23 22:36:15.058103844 +0000
@@ -691,7 +691,8 @@
 
 #elif defined(HAVE_LIBSTATGRAB)
 	sg_disk_io_stats *ds;
-	int disks, counter;
+	size_t disks;
+	int counter;
 	char name[DATA_MAX_NAME_LEN];
 	
 	if ((ds = sg_get_disk_io_stats(&disks)) == NULL)
