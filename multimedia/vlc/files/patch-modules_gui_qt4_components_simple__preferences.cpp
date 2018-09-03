Fix build with Qt 5.11

--- modules/gui/qt4/components/simple_preferences.cpp.orig	2018-09-03 09:38:13 UTC
+++ modules/gui/qt4/components/simple_preferences.cpp
@@ -36,6 +36,7 @@
 #include <QString>
 #include <QFont>
 #include <QToolButton>
+#include <QButtonGroup>
 #include <QSignalMapper>
 #include <QVBoxLayout>
 #include <QScrollArea>
