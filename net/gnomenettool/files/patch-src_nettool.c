--- src/nettool.c.orig	Sun Jul  4 15:52:03 2004
+++ src/nettool.c	Sun Jul  4 15:53:11 2004
@@ -21,6 +21,7 @@
 #include <gnome.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
