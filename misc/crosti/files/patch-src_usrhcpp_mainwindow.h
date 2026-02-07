Fix build with Qt 5.11

--- src/usrhcpp/mainwindow.h.orig	2018-08-31 06:10:35 UTC
+++ src/usrhcpp/mainwindow.h
@@ -40,6 +40,7 @@ along with crosti.  If not, see <http://www.gnu.org/li
 #include <QPrinter>
 #endif
 
+#include <QActionGroup>
 #include <QFileInfo>
 
 class CMiniMap;
