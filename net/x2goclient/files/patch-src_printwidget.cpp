--- src/printwidget.cpp.orig	2019-03-09 16:48:28 UTC
+++ src/printwidget.cpp
@@ -26,6 +26,8 @@
 #ifdef Q_OS_WIN
 #include "wapi.h"
 #endif
+#include <QButtonGroup>
+
 PrintWidget::PrintWidget ( QWidget* parent )
 		: QWidget ( parent )
 {
