--- src/config.c.orig	2018-04-15 19:13:39 UTC
+++ src/config.c
@@ -57,7 +57,7 @@
 #include <getopt.h>
 
 #define OLD_DEFAULT_CFG_FILE "/etc/ocserv.conf"
-#define DEFAULT_CFG_FILE "/etc/ocserv/ocserv.conf"
+#define DEFAULT_CFG_FILE "/usr/local/etc/ocserv/conf"
 
 static void print_version(void);
 
