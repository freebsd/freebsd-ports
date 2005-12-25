--- src/redir.c.orig	Mon Dec 26 08:13:05 2005
+++ src/redir.c	Mon Dec 26 08:22:35 2005
@@ -9,15 +9,15 @@
  *
  */
 
-#include <sys/socket.h>
-#include <netinet/in.h>
-
 #include <stdlib.h>
 #include <stdio.h>
 #include <syslog.h>
 #include <errno.h>
 #include <stdarg.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <string.h>
 #include <fcntl.h>
