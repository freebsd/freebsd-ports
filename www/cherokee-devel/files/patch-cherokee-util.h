--- cherokee/util.h.orig	Tue Sep 20 01:44:20 2005
+++ cherokee/util.h	Tue Sep 20 11:56:57 2005
@@ -30,13 +30,21 @@
 #define CHEROKEE_UTIL_H
 
 #include <cherokee/common.h>
+#include <time.h>
+#include <dirent.h>
+#include <sys/types.h>
+
+#ifdef HAVE_SYS_SOCKET_H
+# include <sys/socket.h>
+#endif
+
+#ifdef HAVE_ARPA_INET_H
+# include <arpa/inet.h>
+#endif
 
 #ifdef HAVE_NETINET_IN_H
 # include <netinet/in.h>
 #endif
-
-#include <time.h>
-#include <dirent.h>
 
 #include <cherokee/buffer.h>
 
