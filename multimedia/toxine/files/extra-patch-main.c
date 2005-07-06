FreeBSD 4.X does not have O_SYNC yet

--- src/main.c.orig	Mon Apr 12 17:55:02 2004
+++ src/main.c	Wed Jul  6 12:16:42 2005
@@ -207,7 +207,7 @@
       {
 	char *ofile = (optarg) ? optarg : "toxine.out";
 	
-	if((tox->msg_fd = open(ofile, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0644)) < 0) {
+	if((tox->msg_fd = open(ofile, O_WRONLY | O_CREAT | O_TRUNC | O_FSYNC, 0644)) < 0) {
 	  fprintf(stderr, "Cannot open %s: %s\n", ofile, strerror(errno));
 	  exit(1);
 	}
