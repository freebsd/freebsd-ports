--- ./cliserv.h.orig	2012-05-25 17:09:16.000000000 +0900
+++ ./cliserv.h	2013-04-04 19:36:34.000000000 +0900
@@ -15,6 +15,8 @@
 #include <netinet/tcp.h>
 #include <netinet/in.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #if SIZEOF_UNSIGNED_SHORT_INT==4
 typedef unsigned short u32;
