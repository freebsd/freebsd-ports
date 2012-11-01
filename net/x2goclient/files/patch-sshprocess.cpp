--- sshprocess.cpp.orig	2011-11-25 21:08:10.000000000 +0900
+++ sshprocess.cpp	2011-12-20 01:53:47.000000000 +0900
@@ -21,6 +21,9 @@
 #include <QTimer>
 
 #ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
 #endif
