--- libmsn-0.1/msn/connection.cpp.orig	Tue Jun 29 07:17:07 2004
+++ libmsn-0.1/msn/connection.cpp	Thu Jul  1 17:04:36 2004
@@ -27,8 +27,8 @@
 #include <msn/externals.h>
 
 #ifndef WIN32
-#include <sys/socket.h>
 #include <unistd.h>
+#include <sys/socket.h>
 #else
 #include <winsock.h>
 #include <io.h>
