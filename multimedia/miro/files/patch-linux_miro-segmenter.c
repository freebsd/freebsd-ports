--- linux/miro-segmenter.c.orig	2012-01-15 13:57:34.494670887 +0100
+++ linux/miro-segmenter.c	2012-01-15 13:57:40.513497721 +0100
@@ -25,6 +25,10 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #include <arpa/inet.h>
 
 #include <errno.h>
