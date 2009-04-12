--- libssh/server.c.orig	2009-04-12 20:06:06.000000000 +1000
+++ libssh/server.c	2009-04-12 20:06:16.000000000 +1000
@@ -27,6 +27,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <errno.h>
 #include <string.h>
