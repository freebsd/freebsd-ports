--- prayer/mydb.c.orig	Thu Feb 17 23:09:40 2005
+++ prayer/mydb.c	Thu Feb 17 23:06:11 2005
@@ -49,12 +49,12 @@
 #include <string.h>
 #include <stdio.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <syslog.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
