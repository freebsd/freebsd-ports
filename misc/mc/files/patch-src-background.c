--- src/background.c.orig	Sat Sep 28 12:10:29 2002
+++ src/background.c	Tue Jun 15 03:17:55 2004
@@ -142,7 +142,7 @@
 	close (1);
 	close (2);
 
-	if ((nullfd = open ("/dev/null", O_RDONLY)) != -1){
+	if ((nullfd = open ("/dev/null", O_RDWR)) != -1){
 	    while (dup2 (nullfd, 0) == -1 && errno == EINTR)
 		    ;
 	    while (dup2 (nullfd, 1) == -1 && errno == EINTR)
