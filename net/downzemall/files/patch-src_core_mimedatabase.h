Fix build with Qt 6.6.x

https://github.com/setvisible/DownZemAll/issues/120
https://github.com/setvisible/DownZemAll/pull/121

--- src/core/mimedatabase.h.orig	2023-11-19 21:20:25 UTC
+++ src/core/mimedatabase.h
@@ -20,6 +20,7 @@
 
 #include <QtCore/QString>
 #include <QtCore/QStringList>
+#include <QtCore/QUrl>
 #include <QtGui/QPixmap>
 
 constexpr int default_icon_size = 32;
