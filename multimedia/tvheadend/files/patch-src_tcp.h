--- src/tcp.h.orig	2015-09-25 13:57:59 UTC
+++ src/tcp.h
@@ -19,6 +19,8 @@
 #ifndef TCP_H_
 #define TCP_H_
 
+#include <sys/socket.h>
+
 #include "htsbuf.h"
 #include "htsmsg.h"
 
