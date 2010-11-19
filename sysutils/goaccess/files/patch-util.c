--- ./util.c.orig	2010-11-17 11:23:54.000000000 +0100
+++ ./util.c	2010-11-17 11:24:10.000000000 +0100
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <netdb.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <errno.h>
