--- src/salut-self.c.orig	Thu Apr 19 17:09:13 2007
+++ src/salut-self.c	Thu Apr 19 17:10:24 2007
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <errno.h>
 
