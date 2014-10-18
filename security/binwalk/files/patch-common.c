--- common.c.orig	2014-10-08 12:07:33.000000000 -0400
+++ common.c	2014-10-08 12:07:45.000000000 -0400
@@ -109,7 +109,7 @@
 
 	if(file_size > 0)
 	{
-		buffer = mmap(NULL, file_size, PROT_READ, (MAP_SHARED | MAP_NORESERVE), fd, 0);
+		buffer = mmap(NULL, file_size, PROT_READ, MAP_SHARED, fd, 0);
 		if(buffer == MAP_FAILED)
 		{
 			perror("mmap");
