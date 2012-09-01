--- modules/gui/qt4/util/pictureflow.cpp.orig
+++ modules/gui/qt4/util/pictureflow.cpp
@@ -28,15 +28,15 @@
 #include "pictureflow.hpp"
 #include "components/playlist/ml_model.hpp"
 
-#include <QApplication>
-#include <QImage>
-#include <QKeyEvent>
-#include <QPainter>
-#include <QPixmap>
-#include <QTimer>
-#include <QVector>
-#include <QWidget>
-#include <QHash>
+#include <qt4/QtGui/QApplication>
+#include <qt4/QtGui/QImage>
+#include <qt4/QtGui/QKeyEvent>
+#include <qt4/QtGui/QPainter>
+#include <qt4/QtGui/QPixmap>
+#include <qt4/QtCore/QTimer>
+#include <qt4/QtCore/QVector>
+#include <qt4/QtGui/QWidget>
+#include <qt4/QtCore/QHash>
 #include "../components/playlist/playlist_model.hpp" /* getArtPixmap etc */
 #include "../components/playlist/sorting.h"          /* Columns List */
 #include "input_manager.hpp"
