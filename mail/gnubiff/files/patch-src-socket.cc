--- src/socket.cc.orig	Sun Mar 20 14:29:15 2005
+++ src/socket.cc	Wed Apr  6 00:30:05 2005
@@ -42,6 +42,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 
+#include <errno.h>
+
 #include "ui-certificate.h"
 #include "mailbox.h"
 #include "socket.h"
