--- third-party/qca/qca-gnupg/qca-gnupg.cpp.orig	2008-02-06 18:10:33.000000000 +0300
+++ third-party/qca/qca-gnupg/qca-gnupg.cpp	2008-02-06 18:10:39.000000000 +0300
@@ -17,6 +17,7 @@
  */
 
 #include <QtCrypto>
+#include <qcaprovider.h>
 #include <QtPlugin>
 
 #ifdef Q_OS_MAC
