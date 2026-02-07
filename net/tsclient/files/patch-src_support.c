--- src/support.c.orig	Tue May 10 07:30:51 2005
+++ src/support.c	Sat May 21 13:47:21 2005
@@ -23,6 +23,8 @@
 #include <fcntl.h> 
 
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
