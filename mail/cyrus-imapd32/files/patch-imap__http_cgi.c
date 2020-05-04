--- imap/http_cgi.c.orig	2020-03-11 03:10:59 UTC
+++ imap/http_cgi.c
@@ -60,6 +60,8 @@
 #include "util.h"
 #include "version.h"
 
+extern char **environ;
+
 /* generated headers are not necessarily in current directory */
 #include "imap/http_err.h"
 #include "imap/imap_err.h"
