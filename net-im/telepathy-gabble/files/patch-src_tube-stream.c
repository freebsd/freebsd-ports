--- src/tube-stream.c.orig	2008-01-17 01:49:11.000000000 -0500
+++ src/tube-stream.c	2008-01-17 01:49:22.000000000 -0500
@@ -24,6 +24,7 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/un.h>
 #include <unistd.h>
 #include <fcntl.h>
