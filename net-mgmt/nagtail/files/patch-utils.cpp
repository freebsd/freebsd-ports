--- utils.cpp.orig	2011-06-01 07:30:26.000000000 -0400
+++ utils.cpp	2011-06-01 07:30:35.000000000 -0400
@@ -29,6 +29,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 extern "C" {
 #include "error.h"
 }
