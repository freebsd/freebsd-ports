--- alclib/mad.h.orig	2016-03-08 14:49:04 UTC
+++ alclib/mad.h
@@ -35,7 +35,10 @@
 #define _MAD_H_
 
 #ifdef LINUX
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #endif
 
 #include "utils.h"
