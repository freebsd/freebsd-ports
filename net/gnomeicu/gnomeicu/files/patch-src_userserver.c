--- src/userserver.c.orig	Mon Mar 10 16:49:07 2003
+++ src/userserver.c	Mon Mar 10 16:49:16 2003
@@ -27,13 +27,13 @@
 
 #include <gdk/gdk.h>
 #include <gdk/gdkkeysyms.h>
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
