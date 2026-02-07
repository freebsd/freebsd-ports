--- src/httpserver.cpp.orig	2019-12-18 12:22:29 UTC
+++ src/httpserver.cpp
@@ -30,6 +30,7 @@
 #include <event2/keyvalq_struct.h>
 
 #include <support/events.h>
+#include <deque>
 
 #ifdef EVENT__HAVE_NETINET_IN_H
 #include <netinet/in.h>
