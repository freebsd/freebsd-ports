--- spioutils.cpp.orig	Sat Aug 11 20:49:44 2007
+++ spioutils.cpp	Sat Aug 11 20:50:00 2007
@@ -3,6 +3,7 @@
  * For license terms, see the file COPYING along with this library.
  */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
