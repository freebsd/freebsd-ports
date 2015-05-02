--- echo.cpp.orig	2014-08-06 10:11:40.000000000 -0400
+++ echo.cpp	2014-08-06 10:11:56.000000000 -0400
@@ -20,6 +20,7 @@
 #include "echo.h"
 #include "exception.h"
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
