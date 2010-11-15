--- src/libnet_write.c.orig	2010-11-03 19:35:12.000000000 +0100
+++ src/libnet_write.c	2010-11-15 18:24:35.000000000 +0100
@@ -32,6 +32,7 @@
  *
  */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/udp.h>
 
