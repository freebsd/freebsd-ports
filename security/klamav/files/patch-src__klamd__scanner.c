--- src/klamd/scanner.c.orig	2007-12-19 08:33:50.000000000 -0200
+++ src/klamd/scanner.c	2007-12-19 08:36:04.000000000 -0200
@@ -396,7 +396,7 @@
 
     logg("*Accepted connection on port %d, fd %d\n", port, acceptd);
 
-    if ((tmpname = cli_gentempdesc(NULL, &tmpd)) == NULL) {
+    if (cli_gentempfd(NULL, &tmpname, &tmpd) ) {
 	shutdown(sockfd, 2);
 	close(sockfd);
 	close(acceptd);
