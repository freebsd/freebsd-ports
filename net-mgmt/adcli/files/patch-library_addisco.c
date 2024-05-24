--- library/addisco.c.orig	2022-09-28 17:04:28 UTC
+++ library/addisco.c
@@ -32,6 +32,7 @@
 
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
+#include <netinet/in.h>
 
 #include <assert.h>
 #include <netdb.h>
