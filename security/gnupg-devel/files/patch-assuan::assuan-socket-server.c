--- assuan/assuan-socket-server.c.orig	Wed Jan 29 15:27:13 2003
+++ assuan/assuan-socket-server.c	Wed Jan 29 15:27:38 2003
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
