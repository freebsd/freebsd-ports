--- lib/localsocket.h.orig	Fri Jan 26 03:40:07 2007
+++ lib/localsocket.h	Fri Jan 26 03:40:23 2007
@@ -24,6 +24,7 @@
 #define LOCALSOCKET_H
 
 #include <string>
+#include <sys/socket.h>
 #include <sys/un.h>
 #include "netsocket.h"
 
