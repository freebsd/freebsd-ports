--- src/apinger.h.old	2008-07-10 22:38:08.000000000 +0200
+++ src/apinger.h	2008-07-10 22:38:29.000000000 +0200
@@ -119,7 +119,7 @@
 
 extern int icmp_sock;
 extern int icmp6_sock;
-extern int ident;
+extern uint16_t ident;
 
 extern struct timeval next_probe;
 
