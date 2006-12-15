--- cherokee/handler_cgi_base.c.orig	Mon Dec 11 11:44:26 2006
+++ cherokee/handler_cgi_base.c	Thu Dec 14 10:09:38 2006
@@ -21,7 +21,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  * USA
  */
-
+#include <stdlib.h>
+#include <limits.h>
 #include "common-internal.h"
 #include "handler_cgi_base.h"
 
