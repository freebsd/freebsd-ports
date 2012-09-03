--- include/atalk/util.h.orig	2010-06-09 18:45:10.000000000 -0400
+++ include/atalk/util.h	2010-06-09 18:45:22.000000000 -0400
@@ -17,6 +17,7 @@
 
 #include <sys/cdefs.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
