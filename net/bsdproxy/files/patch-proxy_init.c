diff -urN -x .svn ../../branches/vendor/bsdproxy/proxy_init.c ./proxy_init.c
--- ../../branches/vendor/bsdproxy/proxy_init.c	2008-06-08 22:30:53.000000000 +0300
+++ ./proxy_init.c	2008-06-08 23:01:32.000000000 +0300
@@ -10,6 +10,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <string.h>
 #include <unistd.h>
 #include <time.h>
 #include "config.h"
