--- twhttpd.c.orig	Tue Apr  1 12:06:08 2003
+++ twhttpd.c	Sun Feb  4 20:07:02 2007
@@ -28,15 +28,17 @@
 #include <netdb.h>
 #include <regex.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
 #include <signal.h>
 #include <time.h>
 #include <unistd.h>
-#include <wait.h>
-#include <netinet/in.h>
-#include <sys/socket.h>
+#include <sys/wait.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 
@@ -4014,7 +4016,7 @@
         lz_flush(hd->fd, &hd->fd_lzb);
     }
     syslog(LOG_ERR, "Exiting Testing Server\n");
-    exit;
+    exit(0);
 }
 
 //////////////////////////////////////////////////////////////////////
