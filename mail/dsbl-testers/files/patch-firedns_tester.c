--- firedns/tester.c.orig	Sun May  9 10:29:54 2004
+++ firedns/tester.c	Sun May  9 10:30:18 2004
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/time.h>
