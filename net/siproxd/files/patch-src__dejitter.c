--- src/dejitter.c.orig	2014-07-10 16:37:54.000000000 +0200
+++ src/dejitter.c	2014-07-10 16:38:40.000000000 +0200
@@ -24,6 +24,8 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/time.h>
+#include <string.h>
 #include <netinet/in.h>
 
 #include <osipparser2/osip_parser.h>
