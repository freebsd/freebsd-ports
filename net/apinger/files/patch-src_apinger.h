--- src/apinger.h.orig	2002-12-20 09:19:57 UTC
+++ src/apinger.h
@@ -112,14 +112,14 @@ struct piped_info {
 };
 #endif
 
-struct target *targets;
+extern struct target *targets;
 
 extern int foreground;
 extern char *config_file;
 
 extern int icmp_sock;
 extern int icmp6_sock;
-extern int ident;
+extern uint16_t ident;
 
 extern struct timeval next_probe;
 
