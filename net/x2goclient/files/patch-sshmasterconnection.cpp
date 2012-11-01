--- sshmasterconnection.cpp.orig	2011-11-25 21:08:10.000000000 +0900
+++ sshmasterconnection.cpp	2011-12-20 01:50:14.000000000 +0900
@@ -25,6 +25,9 @@
 #include <QDir>
 #include <QTemporaryFile>
 #ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 
