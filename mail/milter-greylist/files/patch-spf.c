--- spf.c.orig	Wed Apr 14 10:46:14 2004
+++ spf.c	Thu Apr 29 15:19:01 2004
@@ -45,8 +45,8 @@
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #include "conf.h"
 #include "spf.h"
