--- src/v7recv.c.orig	Fri Apr  2 15:27:50 2004
+++ src/v7recv.c	Fri Apr  2 15:28:03 2004
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <fcntl.h>
