--- ingests.c.orig	2018-06-12 15:18:47 UTC
+++ ingests.c
@@ -31,6 +31,8 @@
 #include <string.h>
 #include <errno.h>
 #include <syslog.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 
 #include <bitstream/mpeg/ts.h>
 
