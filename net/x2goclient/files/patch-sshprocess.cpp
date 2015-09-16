--- src/sshprocess.cpp.orig	2015-05-26 19:13:12 UTC
+++ src/sshprocess.cpp
@@ -24,6 +24,9 @@
 
 #include <QProcess>
 #ifndef Q_OS_WIN
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
 #endif
