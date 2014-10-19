--- src/widget/emoticonswidget.cpp
+++ src/widget/emoticonswidget.cpp
@@ -25,6 +25,8 @@
 #include <QGridLayout>
 #include <QMouseEvent>
 
+#include <math.h>
+
 EmoticonsWidget::EmoticonsWidget(QWidget *parent) :
     QMenu(parent)
 {

