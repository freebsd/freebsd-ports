--- twhttpd.c.orig	Tue Apr  1 13:06:08 2003
+++ twhttpd.c	Mon Jun 26 02:47:58 2006
@@ -33,10 +33,11 @@
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
 
@@ -4014,7 +4015,7 @@
         lz_flush(hd->fd, &hd->fd_lzb);
     }
     syslog(LOG_ERR, "Exiting Testing Server\n");
-    exit;
+    exit(0);
 }
 
 //////////////////////////////////////////////////////////////////////
