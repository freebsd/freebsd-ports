--- kst/kst/emailthread.cpp.orig	Wed Oct 13 15:09:20 2004
+++ kst/kst/emailthread.cpp	Wed Oct 13 15:13:23 2004
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <sys/types.h>
 #include <netdb.h>
 #include <sys/socket.h>
 #include <ctype.h>
