--- search_mode.c.orig	Thu Oct 12 23:36:05 2000
+++ search_mode.c	Sat Feb 24 15:14:47 2001
@@ -16,6 +16,12 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
 
+#include<sys/param.h>
+#if (defined(BSD) && (BSD>=199103))
+    /* Required by regex.h on FreeBSD 4.2 at least. */
+    #include<sys/types.h>
+#endif
+
 #include <fnmatch.h>
 #include<stdio.h>
 #include<string.h>
