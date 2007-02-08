--- src/MessengerThread.cpp.orig	Fri May 28 05:02:18 2004
+++ src/MessengerThread.cpp	Mon Jan 29 21:58:13 2007
@@ -2,8 +2,10 @@
 #include "MessengerContacts.h"
 #include <iostream>
 #include <netdb.h>
-#include <sys/time.h>
+#include <errno.h>
 #include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
