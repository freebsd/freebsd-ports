--- cl/src/get-cl.c.orig	Thu Sep 12 23:54:01 2002
+++ cl/src/get-cl.c	Thu Sep 12 23:54:44 2002
@@ -44,7 +44,7 @@
 	
 	for(i = 0; i < 5; i++) {
 		snprintf(path, PATHLEN, "/tmp/scrollkeeper-tempfile.%d", i);
-		if (stat(path, &buf) == -1) {
+		if (lstat(path, &buf) == -1) {
 			if (errno == ENOENT) {
 				/* this is an empty slot so use it */
 				
