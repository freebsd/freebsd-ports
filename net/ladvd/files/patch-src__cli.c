--- ./src/cli.c.orig	2012-01-01 16:17:19.000000000 -0800
+++ ./src/cli.c	2013-10-20 23:18:59.000000000 -0700
@@ -24,6 +24,7 @@
 #include <sys/file.h>
 #include <sys/un.h>
 #include <netdb.h>
+#include <limits.h>
 
 extern struct proto protos[];
 int status = EXIT_SUCCESS;
