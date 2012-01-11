--- src/QXmppSrvInfo.h.orig	2012-01-07 19:34:05.556368712 +0000
+++ src/QXmppSrvInfo.h	2012-01-07 19:34:38.676876486 +0000
@@ -27,6 +27,13 @@
 #include <QList>
 #include <QString>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <netinet/ip.h>
+#endif 
+
 class QObject;
 class QXmppSrvInfoPrivate;
 class QXmppSrvRecordPrivate;
