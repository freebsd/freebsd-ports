--- net.c.orig	2014-10-02 12:12:58.000000000 +0200
+++ net.c	2014-10-02 12:13:09.000000000 +0200
@@ -26,11 +26,11 @@
 #include <string.h>
 #include <stdlib.h>
 #include <assert.h>
+#include <sys/types.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/fcntl.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <errno.h>
 #include <stdio.h>
