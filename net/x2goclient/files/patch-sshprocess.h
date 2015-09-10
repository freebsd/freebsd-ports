--- src/sshprocess.h.orig	2015-05-26 19:13:12 UTC
+++ src/sshprocess.h
@@ -18,6 +18,12 @@
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
 #include <QProcess>
