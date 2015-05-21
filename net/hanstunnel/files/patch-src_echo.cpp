--- src/echo.cpp.orig	2014-02-07 03:36:31 UTC
+++ src/echo.cpp
@@ -19,7 +19,7 @@
 
 #include "echo.h"
 #include "exception.h"
-
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
