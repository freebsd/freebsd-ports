--- utils.cpp.orig	Thu Feb 28 14:48:39 2008
+++ utils.cpp	Thu Feb 28 15:11:48 2008
@@ -29,6 +29,9 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <arpa/inet.h>
+#include <netinet/in.h>
+#include <strfunc.h>
 extern "C" {
 #include "error.h"
 }
