--- smtp-api.c.orig	Tue Mar  6 21:28:55 2001
+++ smtp-api.c	Tue Mar  6 21:29:15 2001
@@ -20,6 +20,8 @@
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <sys/types.h>
+
 #include <stdarg.h>
 #include <string.h>
 #include <stdlib.h>
