--- src/pgina_pam_server.c.orig	Fri Sep 12 10:30:13 2003
+++ src/pgina_pam_server.c	Thu Apr 29 13:11:51 2004
@@ -148,6 +148,11 @@
 	
 */
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
 #include "pgina_pam_server.h"
 #include "access.h"
 #include "actions.h"
