--- src/tcpservertest.cpp.orig	2012-12-03 14:28:35.000000000 +0100
+++ src/tcpservertest.cpp	2012-12-03 14:28:46.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <sys/types.h>
@@ -30,6 +30,7 @@
 
 #include "tcpsocket.h"
 
+int
 main() {
    printf("\r\nInit Object...");
    TCPSocket *MyServerSocket = new TCPSocket;
@@ -67,5 +68,6 @@
       while(waitpid(-1, NULL, WNOHANG) > 0);
   }
       
+  return 0;
  }
 
