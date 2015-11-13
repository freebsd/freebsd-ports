--- src/apinger.h.orig	2002-12-20 09:19:57 UTC
+++ src/apinger.h
@@ -119,7 +119,7 @@ extern char *config_file;
 
 extern int icmp_sock;
 extern int icmp6_sock;
-extern int ident;
+extern uint16_t ident;
 
 extern struct timeval next_probe;
 
