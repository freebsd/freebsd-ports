--- src/v7login.c.orig	Fri Apr  2 15:25:21 2004
+++ src/v7login.c	Fri Apr  2 15:25:57 2004
@@ -18,6 +18,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
 #include <fcntl.h>
