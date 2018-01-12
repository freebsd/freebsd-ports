--- utils.cpp.orig	2017-12-27 12:07:16 UTC
+++ utils.cpp
@@ -10,6 +10,9 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <arpa/inet.h>
+#include <netinet/in.h>
+#include <strfunc.h>
 extern "C" {
 #include "error.h"
 }
