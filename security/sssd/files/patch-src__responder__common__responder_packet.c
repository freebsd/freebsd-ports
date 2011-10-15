--- ./src/responder/common/responder_packet.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/responder/common/responder_packet.c	2011-10-13 12:15:03.000000000 -0400
@@ -192,7 +192,7 @@
     }
 
     if (rb == 0) {
-        return ENODATA;
+        return ECONNRESET;
     }
 
     if (*packet->len > packet->memsize) {
