--- src/fileops.c.orig	2011-07-21 15:59:01.000000000 +0300
+++ src/fileops.c	2011-08-29 22:03:45.000000000 +0300
@@ -1255,7 +1255,7 @@
 
 	stat(temp_file, &st_after);
 
-	if(memcmp(&st_after.st_mtim, &st_before.st_mtim,
+	if(memcmp(&st_after.st_mtime, &st_before.st_mtime,
 			sizeof(st_after.st_mtime)) == 0)
 	{
 		unlink(temp_file);
