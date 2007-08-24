--- spserver/spioutils.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/spioutils.cpp	Thu Aug 23 07:33:27 2007
@@ -3,6 +3,7 @@
  * For license terms, see the file COPYING along with this library.
  */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
