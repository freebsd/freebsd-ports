--- viewstat.c.orig	Wed Nov 19 12:49:59 2003
+++ viewstat.c	Wed Nov 19 12:50:15 2003
@@ -122,7 +122,7 @@
  		if (fstat(fd,&filestat)) Quit("fstat"); 
 
 		printf("Number of clusters = %d\n",
-		(int)	filestat.st_size / sizeof (clusterItem));
+		(int)	filestat.st_size / (int) sizeof (clusterItem));
 	}
 
 	while ( sizeof(clusterItem) == read( fd, &temp, sizeof(clusterItem)) ) {
