--- protocol.c.orig	Thu Mar 22 13:27:34 2001
+++ protocol.c	Sat Mar 31 15:14:32 2001
@@ -17,6 +17,8 @@
  */
 #include <stdio.h>
 #include <malloc.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <string.h>
@@ -24,7 +26,6 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/types.h>
 #include <ctype.h>
 #include <time.h>
 
