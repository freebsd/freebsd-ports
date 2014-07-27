--- src/zm_comms.h.orig	2009-10-14 06:08:49.000000000 -0700
+++ src/zm_comms.h	2014-07-23 08:26:15.000000000 -0700
@@ -26,9 +26,12 @@
 #include <netdb.h>
 #include <errno.h>
 #include <sys/un.h>
-
+#include <sys/socket.h>
 #include <set>
 #include <vector>
+#include <sys/uio.h>
+#include <netinet/in.h>
+#include <string.h>
 
 class CommsException : public Exception
 {
