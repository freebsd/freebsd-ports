Fix build with Qt 5.11

--- modules/gui/qt4/actions_manager.hpp.orig	2018-09-03 09:20:39 UTC
+++ modules/gui/qt4/actions_manager.hpp
@@ -31,6 +31,7 @@
 #include "qt4.hpp"
 #include "util/singleton.hpp"
 
+#include <QAction>
 #include <QObject>
 class QAction;
 
