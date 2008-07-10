--- third-party/qca/qca-ossl/qca-ossl.cpp.orig	2007-10-14 18:00:57.000000000 +0400
+++ third-party/qca/qca-ossl/qca-ossl.cpp	2008-02-06 18:09:55.000000000 +0300
@@ -19,6 +19,7 @@
  */
 
 #include <QtCrypto>
+#include <qcaprovider.h>
 
 #include <QDebug>
 #include <QtCore/qplugin.h>
