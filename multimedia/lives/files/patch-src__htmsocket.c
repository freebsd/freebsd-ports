--- src/htmsocket.c.orig	2012-01-17 04:02:52.000000000 +0100
+++ src/htmsocket.c	2012-04-13 23:32:15.000000000 +0200
@@ -12,6 +12,8 @@
 
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 
 #if defined(__sun)
 #include <sys/filio.h>
