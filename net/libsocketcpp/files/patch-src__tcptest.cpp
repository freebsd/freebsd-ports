--- src/tcptest.cpp.orig	2001-02-16 19:45:31.000000000 +0100
+++ src/tcptest.cpp	2012-12-03 14:27:37.000000000 +0100
@@ -22,8 +22,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include "tcpsocket.h"
 
+int
 main() {
 	char *Host = new char[100];
 	char *Buffer = new char[2048];
@@ -62,6 +64,8 @@
 	delete [] Buffer;
 	delete [] Host;
 	delete [] TempMsg;
+
+	return 0;
 }
 
 
