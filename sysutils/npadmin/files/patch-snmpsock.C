--- snmpsock.C.orig	Thu Nov 21 17:55:05 2002
+++ snmpsock.C	Thu Nov 21 17:55:19 2002
@@ -10,6 +10,7 @@
 #include <netdb.h>
 #include <ctype.h>
 #include <errno.h>
+#include <stdlib.h>
 
 #define MAXPACKSIZE 10240
 
