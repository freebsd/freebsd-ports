--- libmsn-0.1/msn/filetransfer.cpp.orig	Tue Jun 29 18:59:04 2004
+++ libmsn-0.1/msn/filetransfer.cpp	Thu Jul  1 17:03:28 2004
@@ -27,6 +27,7 @@
 
 #ifndef WIN32
 #include <unistd.h>
+#include <sys/time.h>
 #include <sys/socket.h>
 #else
 #include <winsock.h>
