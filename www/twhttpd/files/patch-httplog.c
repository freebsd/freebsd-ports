--- httplog.c.orig	Sat Dec  8 23:15:44 2001
+++ httplog.c	Mon Jun 26 02:36:09 2006
@@ -40,10 +40,11 @@
 #include <time.h>
 #include <stdio.h>
 #include <syslog.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/time.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 
 #include "config.h"
 #include "structs.h"
