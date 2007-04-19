--- src/salut-muc-connection.c.orig	Thu Apr 19 17:11:46 2007
+++ src/salut-muc-connection.c	Thu Apr 19 17:11:58 2007
@@ -27,6 +27,8 @@
 #include <sys/socket.h>
 #include <netdb.h>
 
+#include <netinet/in.h>
+
 #include "salut-muc-connection.h"
 #include "salut-muc-connection-signals-marshal.h"
 
