--- src/Interface.cpp.orig	Fri May 21 01:14:12 2004
+++ src/Interface.cpp	Mon Jan 29 20:24:53 2007
@@ -1,9 +1,11 @@
 #include "Interface.h"
 
 #if !defined(_WIN32)
+#include <sys/types.h>
 #include <sys/socket.h>
-#include <sys/ioctl.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
+#include <sys/ioctl.h>
 #endif
 
 #if !defined(_WIN32)
