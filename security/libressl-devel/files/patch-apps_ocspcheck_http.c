--- apps/ocspcheck/http.c.orig	2017-01-27 04:29:45 UTC
+++ apps/ocspcheck/http.c
@@ -18,6 +18,7 @@
 #include <sys/socket.h>
 #include <sys/param.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include <ctype.h>
 #include <err.h>
