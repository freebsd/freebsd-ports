--- stun/stunmessage.c.orig	2009-02-27 23:00:07.000000000 -0500
+++ stun/stunmessage.c	2009-02-27 23:00:27.000000000 -0500
@@ -45,6 +45,7 @@
 #else
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 
