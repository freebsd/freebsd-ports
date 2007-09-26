--- smbval/session.inc.c.orig	Wed Sep 26 12:40:51 2007
+++ smbval/session.inc.c	Wed Sep 26 12:41:45 2007
@@ -21,7 +21,7 @@
  * with this program; if not, write to the Free Software Foundation, Inc., 
  * 675 Mass Ave, Cambridge, MA 02139, USA. */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 static int RFCNB_errno = 0;
