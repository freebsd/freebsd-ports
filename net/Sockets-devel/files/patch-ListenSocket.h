--- ListenSocket.h.orig	Sat Jan 15 23:40:23 2005
+++ ListenSocket.h	Sat Jan 15 23:41:10 2005
@@ -31,6 +31,7 @@
 
 #include "Socket.h"
 
+#include <StdLog.h>
 
 template <class X>
 class ListenSocket : public Socket
