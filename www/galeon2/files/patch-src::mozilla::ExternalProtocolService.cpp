
$FreeBSD$

--- src/mozilla/ExternalProtocolService.cpp	2002/05/24 10:52:44	1.1
+++ src/mozilla/ExternalProtocolService.cpp	2002/05/24 10:53:41
@@ -16,7 +16,12 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
 #include <gtk/gtk.h>
 
 #include "ExternalProtocolService.h"
