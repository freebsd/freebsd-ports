--- src/http.c.orig	Sat Apr 19 02:22:23 2003
+++ src/http.c	Sat Apr 19 02:22:34 2003
@@ -35,6 +35,9 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <errno.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#define IPPROTO_TCP 6
 
 #include "http.h"
 
