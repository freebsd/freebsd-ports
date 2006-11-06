--- src/http.c.orig
+++ src/http.c
@@ -38,6 +38,10 @@
 #include "http.h"
 #include "utils.h"
 
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#define IPPROTO_TCP 6
+
 /*
 #define LOG
 */
