--- spserver/teststress.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/teststress.cpp	Thu Aug 23 07:34:03 2007
@@ -18,7 +18,7 @@
 /* For inet_ntoa. */
 #include <arpa/inet.h>
 
-#include "config.h"
+//#include "config.h"
 #include "event.h"
 
 static const char * gHost = "127.0.0.1";
