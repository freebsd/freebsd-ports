--- dissipate2/messagesocket.h.orig	Mon Jul  5 13:49:27 2004
+++ dissipate2/messagesocket.h	Mon Jul  5 13:50:01 2004
@@ -23,6 +23,7 @@
 #define MESSAGESOCKET_H_INCLUDED
 
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 
 class MessageSocket
