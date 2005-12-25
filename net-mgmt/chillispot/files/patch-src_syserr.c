--- src/syserr.c.orig	Mon Dec 26 08:30:20 2005
+++ src/syserr.c	Mon Dec 26 08:30:46 2005
@@ -10,13 +10,13 @@
  */
 
 #include <stdarg.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 
 #include "syserr.h"
 
