--- sources/djvumodel.cpp.orig	2020-05-21 10:55:32 UTC
+++ sources/djvumodel.cpp
@@ -29,6 +29,7 @@ along with qpdfview.  If not, see <http://www.gnu.org/
 #include <cstdio>
 
 #include <QFile>
+#include <QPainterPath>
 #include <qmath.h>
 
 #if defined(Q_OS_WIN) && defined(DJVU_STATIC)
