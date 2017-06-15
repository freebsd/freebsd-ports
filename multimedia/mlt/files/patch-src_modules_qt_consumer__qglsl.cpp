--- src/modules/qt/consumer_qglsl.cpp.orig	2016-11-16 06:53:11 UTC
+++ src/modules/qt/consumer_qglsl.cpp
@@ -20,13 +20,14 @@
 #include "common.h"
 #include <framework/mlt.h>
 #include <QApplication>
-#include <QGLWidget>
-#include <QMutex>
-#include <QWaitCondition>
 #include <QtGlobal>
 
 #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
 
+#include <QGLWidget>
+#include <QMutex>
+#include <QWaitCondition>
+
 class GLWidget : public QGLWidget
 {
 private:
