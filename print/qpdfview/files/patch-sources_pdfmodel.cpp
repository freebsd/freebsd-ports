--- sources/pdfmodel.cpp.orig	2017-08-29 10:20:07.908315000 -0700
+++ sources/pdfmodel.cpp	2017-08-29 10:21:13.178844000 -0700
@@ -37,6 +37,7 @@ along with qpdfview.  If not, see <http://www.gnu.org/
 
 #endif // QT_VERSION
 
+#include <sys/types.h>
 #include <poppler-form.h>
 
 #include "annotationwidgets.h"
