--- lib/src/gretl_utils.c.orig	Mon Sep 30 06:13:40 2002
+++ lib/src/gretl_utils.c	Mon Oct 21 08:31:52 2002
@@ -1373,8 +1373,8 @@
 	if (home != NULL) {
 	    strcpy(ppaths->gretldir, home);
 	} else {
-	    strcpy(ppaths->gretldir, GRETL_PREFIX);
-	    strcat(ppaths->gretldir, "/share/gretl/");
+	    strcpy(ppaths->gretldir, DATADIR);
+	    strcat(ppaths->gretldir, "/gretl/");
 	} 
 	if (gui) {
 	    sprintf(ppaths->binbase, "%sdb/", ppaths->gretldir);
