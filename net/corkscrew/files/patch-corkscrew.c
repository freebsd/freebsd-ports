--- corkscrew.c.orig	Mon Aug 27 16:42:20 2001
+++ corkscrew.c	Mon Aug 27 16:44:02 2001
@@ -1,15 +1,15 @@
 #include "config.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <netdb.h>
-#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/socket.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #if HAVE_SYS_FILIO_H
