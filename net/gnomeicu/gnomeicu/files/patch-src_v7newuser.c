--- src/v7newuser.c.orig	Fri Apr  2 15:26:51 2004
+++ src/v7newuser.c	Fri Apr  2 15:27:04 2004
@@ -19,6 +19,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <fcntl.h>
