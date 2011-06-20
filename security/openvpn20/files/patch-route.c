--- ./route.c.orig	2006-04-05 08:13:55.000000000 +0200
+++ ./route.c	2011-06-20 23:19:43.000000000 +0200
@@ -1310,6 +1310,7 @@
 
 #elif defined(TARGET_FREEBSD)
 
+#include <err.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
