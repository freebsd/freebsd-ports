--- ListenSocket.h.orig	Sun Apr  3 18:43:45 2005
+++ ListenSocket.h	Sun Apr  3 18:44:30 2005
@@ -31,6 +31,7 @@
 
 #include "Socket.h"
 
+#include <StdLog.h>
 
 template <class X>
 class ListenSocket : public Socket
