--- libk9copy/k9backupdlg.cpp.orig     Thu Jan  5 06:08:21 2006
+++ libk9copy/k9backupdlg.cpp  Thu Jan  5 06:08:38 2006
@@ -18,7 +18,11 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
  ***************************************************************************/

-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif
 #include <qtimer.h>
 #include <qdatetime.h>
 #include <qapplication.h>
