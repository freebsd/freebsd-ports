--- kover/net.cc.orig	Mon Dec 29 04:55:16 2003
+++ kover/net.cc	Mon Dec 29 05:01:10 2003
@@ -33,6 +33,9 @@
 #include "kover.h"
 
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <unistd.h>
