--- kaffeine/http.c.orig	Sat Mar 27 23:09:53 2004
+++ kaffeine/http.c	Sat Mar 27 23:15:12 2004
@@ -48,6 +48,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <unistd.h>
