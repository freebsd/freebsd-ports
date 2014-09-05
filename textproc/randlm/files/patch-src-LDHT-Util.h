--- src/LDHT/Util.h.orig	2012-03-30 14:53:05.000000000 +0400
+++ src/LDHT/Util.h	2014-08-30 18:08:50.000000000 +0400
@@ -10,6 +10,10 @@
 #include <cstdlib>
 #include <cstring>
 #include <stdint.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #define V(expr) std::cerr << __FILE__ << ":" \
                           << __LINE__ << " " \
