--- server.h.orig	Fri Sep  3 23:53:20 2004
+++ server.h	Sat Mar 19 16:53:49 2005
@@ -7,7 +7,7 @@
 
 #define NETDUMP_PORT 6666
 
-#define NETDUMP_DIR_PREFIX "/var/crash"
+#define NETDUMP_DIR_PREFIX "/var/spool/netdump"
 
 extern int master_socket;
 
