--- scanner_trophie.c.orig	Thu Dec  4 02:57:56 2003
+++ scanner_trophie.c	Wed Feb 18 12:51:22 2004
@@ -37,11 +37,11 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <errno.h>
-#include <malloc.h>
 #include <sys/un.h>
 #include <sys/socket.h>
 #include <stdarg.h>
 #include <ctype.h>
+#include <netinet/in.h>
 
 #include "p3scan.h"
 
@@ -68,7 +68,7 @@
     if (trophie_fd!=-1 && connected==-1){
       do_log(LOG_DEBUG, "Trying to connect to socket");
       if (connect(trophie_fd, (struct sockaddr *)(&trophie_socket),
-         sizeof(trophie_socket.sun_family) + strlen(config->virusscanner)) >= 0){
+         SUN_LEN(&trophie_socket)) >= 0){
          connected=1;
          do_log(LOG_DEBUG, "trophie_socket_connect connected");
          return 0;
