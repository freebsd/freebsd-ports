diff -urN -x .svn ../../branches/vendor/bsdproxy/proxy.c ./proxy.c
--- ../../branches/vendor/bsdproxy/proxy.c	2008-06-08 22:30:53.000000000 +0300
+++ ./proxy.c	2008-06-08 22:54:00.000000000 +0300
@@ -16,9 +16,6 @@
 #include "config.h"
 #include "proxy_protos.h"
 
-extern char *optarg;
-extern int   optind;
-
 static int sig;
 
 /* usage() */
