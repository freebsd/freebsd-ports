--- src/info.c.orig	Sun Aug 27 21:14:35 2006
+++ src/info.c	Sun Aug 27 21:18:06 2006
@@ -17,7 +17,7 @@
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-
+#include <libgen.h>
 
 void author()
 {
