--- rsync.c.orig	Wed May 16 10:59:08 2007
+++ rsync.c	Wed May 16 10:59:17 2007
@@ -82,7 +82,7 @@
 	long size;
 
 	if ( !conn_gets(buffer, 100) || sscanf(buffer, "octet-stream %ld\n", &size) != 1 ) {
-		if (!strcmp(buffer, "ERROR\n")) { errno=ENODATA; return -1; }
+		if (!strcmp(buffer, "ERROR\n")) { errno=EIO; return -1; }
 		csync_fatal("Format-error while receiving data.\n");
 	}
 
