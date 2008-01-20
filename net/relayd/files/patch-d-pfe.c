--- relayd/pfe.c.orig	2008-01-14 10:06:37.013495830 +0900
+++ relayd/pfe.c	2008-01-14 10:06:47.508856711 +0900
@@ -17,6 +17,7 @@
  */
 
 #include <sys/param.h>
+#include <sys/queue.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/un.h>
