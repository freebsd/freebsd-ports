--- dctc_connection.h.orig	Wed Aug 13 08:54:27 2003
+++ dctc_connection.h	Wed Aug 13 08:54:44 2003
@@ -4,6 +4,7 @@
 #include <qobject.h>
 #include <qsocketdevice.h>
 
+#include <sys/types.h>
 #include <sys/un.h>
 
 class QSocketNotifier;
