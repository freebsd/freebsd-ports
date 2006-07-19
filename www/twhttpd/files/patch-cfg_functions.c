--- cfg_functions.c.orig	Tue Feb 12 23:29:15 2002
+++ cfg_functions.c	Mon Jun 26 02:38:18 2006
@@ -29,10 +29,10 @@
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
