--- utils.cpp.orig	Mon Nov 27 06:21:58 2006
+++ utils.cpp	Sat Apr 28 13:45:23 2007
@@ -29,6 +29,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 extern "C" {
 #include "error.h"
 }
