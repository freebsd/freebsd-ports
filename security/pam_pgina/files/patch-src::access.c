--- src/access.c.orig	Fri Jun 25 23:33:28 2004
+++ src/access.c	Fri Jun 25 23:34:23 2004
@@ -72,6 +72,7 @@
 #include "pgina_pam_server.h"
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 
