--- lib/src/gretl_paths.c.orig	Wed Feb 11 06:14:36 2004
+++ lib/src/gretl_paths.c	Sun Feb 29 18:10:53 2004
@@ -432,8 +432,8 @@
 	if (home != NULL) {
 	    strcpy(ppaths->gretldir, home);
 	} else {
-	    strcpy(ppaths->gretldir, GRETL_PREFIX);
-	    strcat(ppaths->gretldir, "/share/gretl/");
+	    strcpy(ppaths->gretldir, DATADIR);
+	    strcat(ppaths->gretldir, "/gretl/");
 	} 
 
 	sprintf(ppaths->binbase, "%sdb/", ppaths->gretldir);
