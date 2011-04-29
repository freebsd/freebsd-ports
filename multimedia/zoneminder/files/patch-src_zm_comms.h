--- src/zm_comms.h.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_comms.h	2011-04-08 17:48:07.410804476 +0400
@@ -26,10 +26,11 @@
 #include <netdb.h>
 #include <errno.h>
 #include <sys/un.h>
-
+#include <sys/socket.h>
 #include <set>
 #include <vector>
-
+#include <sys/uio.h>
+#include <netinet/in.h>
 class CommsException : public Exception
 {
 public:
