--- cherokee/util.h.orig	Wed Sep 13 22:13:07 2006
+++ cherokee/util.h	Wed Sep 13 22:15:20 2006
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
 #include <time.h>
 #include <dirent.h>
 
