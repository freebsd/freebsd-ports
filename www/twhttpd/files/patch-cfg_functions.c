--- cfg_functions.c.orig	Tue Feb 12 22:29:15 2002
+++ cfg_functions.c	Sun Feb  4 20:07:31 2007
@@ -25,14 +25,16 @@
 #include <ctype.h>
 #include <errno.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <fnmatch.h>
 #include <regex.h>
 #include <syslog.h>
 #include <unistd.h>
-#include <arpa/inet.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #include "y.tab.h"
 #include "twhttpd.h"
@@ -588,14 +590,14 @@
 // change forward destination
 int cfg_set_forward(http_header *hd, void *value, void *value2, int property)
 {
-    (void *)hd->forward = (void *)value;
+    hd->forward = (struct sockaddr_in *)value;
     return 1;
 }
 
 // change web or proxy mode
 int cfg_set_forward_proxy(http_header *hd, void *value, void *value2, int property)
 {
-    (void *)hd->forward_proxy = (void *)value;
+    hd->forward_proxy = (int *)value;
     return 1;
 }
 
