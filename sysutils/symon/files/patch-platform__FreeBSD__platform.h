--- platform/FreeBSD/platform.h.orig	Fri Oct 21 16:58:43 2005
+++ platform/FreeBSD/platform.h	Fri Dec  2 12:03:04 2005
@@ -4,8 +4,10 @@
 #define _CONF_FREEBSD_H
 
 #include <sys/queue.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/time.h>
+#include <sys/dkstat.h>
 #include <sys/resource.h>
 
 #include <net/if.h>
