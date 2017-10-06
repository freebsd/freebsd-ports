--- sources/formfieldwidgets.cpp.orig	2017-08-29 10:19:57.244069000 -0700
+++ sources/formfieldwidgets.cpp	2017-08-29 10:21:31.064929000 -0700
@@ -24,6 +24,7 @@ along with qpdfview.  If not, see <http://www.gnu.org/
 #include <QGraphicsProxyWidget>
 #include <QMutex>
 
+#include <sys/types.h>
 #include <poppler-form.h>
 
 #ifndef HAS_POPPLER_24
