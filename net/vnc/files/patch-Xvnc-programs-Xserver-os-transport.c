--- Xvnc/lib/xtrans/transport.c	Thu Nov  7 23:01:27 2002
+++ Xvnc/lib/xtrans/transport.c	Thu Nov  7 23:02:10 2002
@@ -53,6 +53,7 @@
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdlib.h>
 #ifdef XSERV_t
 #include "os.h"
 #else
