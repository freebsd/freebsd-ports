--- NNTPConnection.h.orig	Fri Apr  2 18:55:19 2004
+++ NNTPConnection.h	Sat Apr 17 22:53:55 2004
@@ -26,6 +26,7 @@
 #ifndef NNTPCONNECTION_H
 #define NNTPCONNECTION_H
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include <vector>
