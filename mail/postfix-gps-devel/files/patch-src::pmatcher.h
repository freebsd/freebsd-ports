--- src/pmatcher.h.orig	Sun Nov 21 05:37:49 2004
+++ src/pmatcher.h	Sun Jan  9 16:50:54 2005
@@ -24,6 +24,7 @@
 #include <string>
 //getnameinfo
 #include <netdb.h>
+#include <sys/socket.h>
 //
 #include "regexcpp.h"
 #include "triplet.h"
