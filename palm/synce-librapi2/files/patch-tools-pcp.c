--- tools/pcp.c.orig	Wed Apr  5 17:58:44 2006
+++ tools/pcp.c	Fri Jan 26 02:34:34 2007
@@ -278,7 +278,7 @@
 			printf("File copy took less than one second!\n");
 		else
 			printf("File copy of %i bytes took %li minutes and %li seconds, that's %li bytes/s.\n",
-					bytes_copied, duration / 60, duration % 60, bytes_copied / duration);
+					bytes_copied, (long)duration / 60, (long)duration % 60, (long)bytes_copied / duration);
 
 	}
 
