--- include.h.orig	Thu Apr 17 11:36:06 2003
+++ include.h	Thu Apr 17 11:36:19 2003
@@ -24,13 +24,13 @@
 *                                              *
 \*____________________________________________*/
 
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/wait.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <unistd.h>
 #include <sys/types.h>
