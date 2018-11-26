Missing includes, these live in QtWidgets now.

--- src/qbrew.cpp.orig	2018-11-26 11:56:17 UTC
+++ src/qbrew.cpp
@@ -9,6 +9,12 @@
 
 #include <QtGui>
 
+#include <QFileDialog>
+#include <QMessageBox>
+#include <QSplashScreen>
+#include <QStyleFactory>
+#include <QWhatsThis>
+
 #include "alcoholtool.h"
 #include "configure.h"
 #include "data.h"
