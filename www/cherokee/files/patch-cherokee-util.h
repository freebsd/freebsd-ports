--- cherokee/util.h.orig	Sat Oct 15 19:31:05 2005
+++ cherokee/util.h	Thu Oct 20 00:59:40 2005
@@ -31,6 +31,14 @@
 
 #include <cherokee/common.h>
 
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+
+#ifdef HAVE_SYS_SOCKET_H
+# include <sys/socket.h>
+#endif
+
 #ifdef HAVE_NETINET_IN_H
 # include <netinet/in.h>
 #endif
