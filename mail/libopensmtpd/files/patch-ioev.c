--- ioev.c.orig	2019-11-14 17:46:37 UTC
+++ ioev.c
@@ -21,6 +21,8 @@
 #include <sys/queue.h>
 #include <sys/socket.h>
 
+#include <netinet/in.h>
+
 #include <err.h>
 #include <errno.h>
 #include <event.h>
