--- a/src/net/cxsocket.c
--- b/src/net/cxsocket.c
@@ -48,6 +48,10 @@
 #include "config/config.h"
 #include "cxsocket.h"
 
+#ifndef MSG_MORE
+#define MSG_MORE 0
+#endif
+
 cxSocket::~cxSocket()
 {
   close();
