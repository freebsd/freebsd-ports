--- s_socket.c.orig	Wed Oct 15 22:32:33 2003
+++ s_socket.c	Wed Oct 15 22:32:45 2003
@@ -67,7 +67,7 @@
 #undef USE_SOCKETS
 #undef NON_MAIN
 #include "s_apps.h"
-#include OPENSSL"ssl.h"
+#include "%%OPENSSL%%/ssl.h"
 
 #ifndef NOPROTO
 static struct hostent *GetHostByName(char *name);
