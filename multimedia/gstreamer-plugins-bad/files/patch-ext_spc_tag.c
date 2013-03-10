--- ext/spc/tag.c.orig	2013-03-10 09:53:25.000000000 +0000
+++ ext/spc/tag.c	2013-03-10 09:53:41.000000000 +0000
@@ -16,9 +16,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#include <glib/gstring.h>
-#include <glib/gtypes.h>
-#include <glib/gmem.h>
+#include <glib.h>
 #include <glib/gprintf.h>
 
 #include <tag.h>
