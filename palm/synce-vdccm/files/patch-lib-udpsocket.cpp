--- lib/udpsocket.cpp.orig	Sun May  7 18:49:36 2006
+++ lib/udpsocket.cpp	Fri Jan 26 19:21:19 2007
@@ -10,6 +10,8 @@
 //
 //
 #include "udpsocket.h"
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <netdb.h>
 
 using namespace std;
