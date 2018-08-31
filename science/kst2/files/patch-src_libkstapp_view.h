Fix build with Qt 5.11

--- src/libkstapp/view.h.orig	2018-08-31 07:50:35 UTC
+++ src/libkstapp/view.h
@@ -14,6 +14,7 @@
 #define VIEW_H
 
 #include <QGraphicsView>
+#include <QMenu>
 
 #include "kst_export.h"
 
