--- src/userserver.c.orig	Fri Apr  2 15:20:45 2004
+++ src/userserver.c	Fri Apr  2 15:20:54 2004
@@ -6,12 +6,12 @@
 ***************************/
 
 #include <errno.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/un.h>
