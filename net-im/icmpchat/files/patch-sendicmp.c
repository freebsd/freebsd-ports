--- sendicmp.c.orig	2003-04-08 10:58:56 UTC
+++ sendicmp.c
@@ -3,6 +3,8 @@
 #include "config.h"
 #include "sendicmp.h"
 
+struct sockaddr_in	saddr;
+
 int 
 sendpacket(int rawsock, 
 	   const unsigned char *text, 
