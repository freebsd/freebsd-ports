--- src/io.c.orig	Wed May 26 09:23:51 2004
+++ src/io.c	Wed May 26 09:24:08 2004
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdarg.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netdb.h>
