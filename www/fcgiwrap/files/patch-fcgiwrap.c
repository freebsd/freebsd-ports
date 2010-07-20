--- ./fcgiwrap.c.orig	2010-06-03 16:18:21.000000000 +0200
+++ ./fcgiwrap.c	2010-06-15 14:54:38.232029168 +0200
@@ -43,6 +43,7 @@
 #include <ctype.h>
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 
