--- src/CGI-test/ws25_cgi.c.orig	1998-07-25 08:49:54 UTC
+++ src/CGI-test/ws25_cgi.c
@@ -62,7 +62,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 
-void
+int
 main()
 {
 	char *query_string;
