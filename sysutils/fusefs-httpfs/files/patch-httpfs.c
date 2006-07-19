--- httpfs.c.orig	Sun Jul 16 22:48:19 2006
+++ httpfs.c	Sun Jul 16 22:48:39 2006
@@ -32,9 +32,10 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/select.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <time.h>
