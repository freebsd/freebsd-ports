--- malsync/mal/common/AGNet.h.orig	Thu Mar 18 19:46:23 2004
+++ malsync/mal/common/AGNet.h	Thu Mar 18 19:46:54 2004
@@ -61,7 +61,7 @@
 #               include <sys/filio.h>
 #               include <arpa/inet.h>
 #           else
-#               if (defined(BSD) && BSD >= 199306) || defined(_HPUX_SOURCE)
+#               if defined(__FreeBSD__)
 #                   include <sys/ioctl.h>
 #                   include <arpa/inet.h>
 #               else
