--- src/log.c.old	Wed Aug  4 04:16:48 2004
+++ src/log.c	Wed Aug  4 04:17:12 2004
@@ -16,6 +16,7 @@
     Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
+#include <sys/stat.h>
 #include "masqmail.h"
 
 #include "sysexits.h"
