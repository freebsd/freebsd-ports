--- gst/gstthreaddummy.c.orig	Mon Jun 30 14:31:13 2003
+++ gst/gstthreaddummy.c	Fri Nov 14 15:36:22 2003
@@ -17,6 +17,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <unistd.h>
 #include <sys/time.h>
 #include <glib.h>
