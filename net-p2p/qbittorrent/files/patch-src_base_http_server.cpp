# Missing header; upstream patch shuffles them a bit
#
--- src/base/http/server.cpp.orig	2017-03-03 23:20:21 UTC
+++ src/base/http/server.cpp
@@ -28,14 +28,18 @@
  * exception statement from your version.
  */
 
+#include "server.h"
+
+#include <QNetworkProxy>
+#include <QStringList>
+
 #ifndef QT_NO_OPENSSL
 #include <QSslSocket>
 #else
 #include <QTcpSocket>
 #endif
-#include <QNetworkProxy>
+
 #include "connection.h"
-#include "server.h"
 
 using namespace Http;
 
