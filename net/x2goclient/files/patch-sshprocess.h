--- sshprocess.h.orig	2011-11-25 21:08:10.000000000 +0900
+++ sshprocess.h	2011-12-20 01:56:29.000000000 +0900
@@ -17,6 +17,12 @@
 #ifndef SSHPROCESS_H
 #define SSHPROCESS_H
 
+#ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#endif
 #include <libssh/libssh.h>
 #include <QObject>
 
