--- ./src/net/address.cpp.orig	2012-02-28 17:35:19.000000000 +0000
+++ ./src/net/address.cpp	2012-03-06 13:36:25.728553394 +0000
@@ -21,6 +21,7 @@
 #include "address.h"
 #include <arpa/inet.h>
 #include <util/log.h>
+#include <sys/socket.h>
 
 using namespace bt;
 
