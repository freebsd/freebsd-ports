--- src/qt/guiutil.h.orig	2014-12-18 14:47:02 UTC
+++ src/qt/guiutil.h
@@ -5,7 +5,9 @@
 #include <QObject>
 #include <QMessageBox>
 
+#ifndef Q_MOC_RUN
 #include <boost/filesystem.hpp>
+#endif
 
 class SendCoinsRecipient;
 
