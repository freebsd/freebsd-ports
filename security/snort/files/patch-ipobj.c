--- src/sfutil/ipobj.c.orig	Fri Dec 19 14:16:33 2003
+++ src/sfutil/ipobj.c	Fri Dec 19 14:18:10 2003
@@ -19,6 +19,7 @@
 #include <string.h>
 
 #ifndef WIN32
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
