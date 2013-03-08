--- lasso/errors.c.orig	2013-02-07 16:40:45.000000000 +0000
+++ lasso/errors.c	2013-02-07 16:40:54.000000000 +0000
@@ -22,7 +22,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
-#include <glib/gstrfuncs.h>
+#include <glib.h>
 #include <lasso/errors.h>
 #include <lasso/xml/xml.h>
 
