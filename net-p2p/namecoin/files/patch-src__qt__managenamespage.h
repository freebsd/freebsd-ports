--- ./src/qt/managenamespage.h.orig	2013-10-29 13:38:10.000000000 +0000
+++ ./src/qt/managenamespage.h	2014-01-18 23:12:20.965138391 +0000
@@ -1,6 +1,9 @@
 #ifndef MANAGENAMESPAGE_H
 #define MANAGENAMESPAGE_H
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include <QDialog>
 #include <QSortFilterProxyModel>
 
