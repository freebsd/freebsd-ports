--- src/qt/managenamespage.h.orig	2014-12-18 14:47:02 UTC
+++ src/qt/managenamespage.h
@@ -1,6 +1,9 @@
 #ifndef MANAGENAMESPAGE_H
 #define MANAGENAMESPAGE_H
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include <QDialog>
 #include <QSortFilterProxyModel>
 
