--- xmit/get_tcp_conn.c.orig	Thu Nov 17 19:15:22 1994
+++ xmit/get_tcp_conn.c	Mon Nov  4 05:19:55 2002
@@ -24,6 +24,9 @@
 #include <netinet/in.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
 #include "get_tcp_conn.h"
 #ifndef	NONETDB
 #include <netdb.h>
