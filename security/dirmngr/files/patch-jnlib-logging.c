--- jnlib/logging.c.orig	Mon Nov 22 14:02:22 2004
+++ jnlib/logging.c	Fri Dec 17 13:03:13 2004
@@ -35,6 +35,7 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <fcntl.h>
