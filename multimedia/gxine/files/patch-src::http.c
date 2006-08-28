--- src/http.c.orig	Thu Jun 29 04:35:39 2006
+++ src/http.c	Tue Jul 11 00:54:35 2006
@@ -35,6 +35,9 @@
 #include <ctype.h>
 #include <errno.h>
 
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#define IPPROTO_TCP 6
 #include "http.h"
 #include "utils.h"
 
