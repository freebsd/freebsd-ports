--- src/socket.cc.bak	Sun Jan  9 14:43:12 2005
+++ src/socket.cc	Sun Jan  9 14:43:22 2005
@@ -40,6 +40,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <sys/time.h>
 
 #include "ui-certificate.h"
 #include "mailbox.h"
