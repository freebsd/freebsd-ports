--- src/userserver.c.orig	Sun Nov 10 03:20:44 2002
+++ src/userserver.c	Sun Nov 10 03:20:56 2002
@@ -25,13 +25,13 @@
 #include "showlist.h"
 
 #include <gdk/gdk.h>
+#include <sys/types.h>
 #include <errno.h>
 #include <netinet/in.h>
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/un.h>
