--- src/qt/configurenamedialog.h.orig	2014-12-18 14:47:02 UTC
+++ src/qt/configurenamedialog.h
@@ -1,6 +1,9 @@
 #ifndef CONFIGURENAMEDIALOG_H
 #define CONFIGURENAMEDIALOG_H
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include <QDialog>
 
 namespace Ui {
