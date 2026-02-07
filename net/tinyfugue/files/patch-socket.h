--- src/socket.h.orig	2007-01-13 23:12:39 UTC
+++ src/socket.h
@@ -21,7 +21,6 @@
 #define CONN_BG		0x08
 #define CONN_FG		0x10
 
-struct World   *world_decl;	/* declares struct World */
 
 extern String *incoming_text;
 extern int quit_flag;
