--- ./src/qt/configurenamedialog.h.orig	2013-10-29 13:38:10.000000000 +0000
+++ ./src/qt/configurenamedialog.h	2014-01-18 23:12:20.925138619 +0000
@@ -1,6 +1,9 @@
 #ifndef CONFIGURENAMEDIALOG_H
 #define CONFIGURENAMEDIALOG_H
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include <QDialog>
 
 namespace Ui {
