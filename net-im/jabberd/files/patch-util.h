--- util/util.h.orig	Mon May 31 16:31:06 2004
+++ util/util.h	Mon Jul 12 10:29:58 2004
@@ -30,6 +30,8 @@
 #include <time.h>
 #include <errno.h>
 #include <assert.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #ifdef HAVE_NETINET_IN_H
 # include <netinet/in.h>
