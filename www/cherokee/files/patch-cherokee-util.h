--- cherokee/util.h.orig	Mon Aug  1 21:47:22 2005
+++ cherokee/util.h	Thu Aug  4 21:05:15 2005
@@ -33,7 +33,19 @@
 #include <cherokee/buffer.h>
 #include <time.h>
 #include <dirent.h>
-#include <netinet/in.h>
+#include <sys/types.h>
+
+#ifdef HAVE_SYS_SOCKET_H
+# include <sys/socket.h>
+#endif
+
+#ifdef HAVE_ARPA_INET_H
+# include <arpa/inet.h>
+#endif
+
+#ifdef HAVE_NETINET_IN_H
+# include <netinet/in.h>
+#endif
 
 
 CHEROKEE_BEGIN_DECLS
