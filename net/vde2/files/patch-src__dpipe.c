--- src/dpipe.c.orig	2011-11-24 01:41:18.000000000 +0900
+++ src/dpipe.c	2011-11-28 03:05:11.000000000 +0900
@@ -201,7 +201,7 @@
 
 	if (daemonize != 0)
 		daemon(0,0);
-	else if (setpgrp() != 0) {
+	else if (setpgrp(0,getpid()) != 0) {
 		fprintf(stderr,"Err: cannot create pgrp\n");
 		exit(1);
 	}
