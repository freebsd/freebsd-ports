--- assuan/assuan-socket-connect.c.orig	Wed Jan 29 15:30:12 2003
+++ assuan/assuan-socket-connect.c	Wed Jan 29 15:30:28 2003
@@ -23,6 +23,7 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <unistd.h>
